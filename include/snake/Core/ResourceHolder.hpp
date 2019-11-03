#ifndef RESOURCEHOLDER_HPP_INCLUDED
#define RESOURCEHOLDER_HPP_INCLUDED

#include <map>
#include <memory>
#include <string>

namespace snake::core {

    template<typename Identifier, typename Resource>
    class ResourceHolder {
    public:
        using ResourcePtr = std::unique_ptr<Resource>;
    public:
        void load(Identifier id, std::string const& filename);
        template<typename Parameter> void load(Identifier id, const std::string& filename, Parameter parameter);
        Resource& get(Identifier id);
        Resource const& get(Identifier id) const;
    private:
        std::map<Identifier, ResourcePtr> mResourceMap;
    };

}

#include <snake/Core/ResourceHolder.inl>

#endif // RESOURCEHOLDER_HPP_INCLUDED
