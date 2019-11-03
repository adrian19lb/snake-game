#include <cassert>
#include <exception>
#include <typeindex>

namespace snake::core {
    
    template<typename Identifier, typename Resource>
    void ResourceHolder<Identifier, Resource>::load(Identifier id, std::string const& filename) {
        std::unique_ptr<Resource> newResource(std::make_unique<Resource>());
        if (!newResource->loadFromFile(filename)) {
            throw std::runtime_error("ResourceHolder::load - failed to load: " + filename);
        }
        auto inserted = mResourceMap.emplace(std::make_pair(id, std::move(newResource)));
        assert(inserted.second);
    }

    template<typename Identifier, typename Resource>
    template<typename Parameter>
    void ResourceHolder<Identifier, Resource>::load(Identifier id, std::string const& filename, Parameter parameter) {
        std::unique_ptr<Resource> newResource(std::make_unique<Resource>());
        if (!newResource->loadFromFile(filename, parameter)) {
            throw std::runtime_error("ResourceHolder::load - failed to load: " + filename);
        }
        auto inserted = mResourceMap.emplace(std::make_pair(id, std::move(newResource)));
        assert(inserted.second);
    }

    template<typename Identifier, typename Resource>
    Resource& ResourceHolder<Identifier, Resource>::get(Identifier id) {
        auto found = mResourceMap.find(id);
        if (found == mResourceMap.end()) {
            throw std::out_of_range("ResourceHolder::get - resource doesn't exist\n");
        }

        return *found->second;
    }

    template<typename Identifier, typename Resource>
    const Resource& ResourceHolder<Identifier, Resource>::get(Identifier id) const {
        auto found = mResourceMap.find(id);
        assert(found != mResourceMap.end());
        return *found->second;
    }

}
