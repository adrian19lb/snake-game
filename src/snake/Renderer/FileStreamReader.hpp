#ifndef FILESTREAMREADER_H
#define FILESTREAMREADER_H

#include <vector>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <iterator>
#include <string>

namespace snake::renderer {
    
    template<typename T>
    class FileStreamReader {
    public:
        using iterator = typename std::vector< std::vector<T> >::iterator;
    public:
        FileStreamReader(std::string const& txtFilename)
        : fileStream(txtFilename) {
            throwIfNullFileStream();
            fillBufferFromFileStream();
            fileStream.close();
        }

        iterator begin() const {
            return buffer.begin(); 
        }

        iterator end() const {
            return buffer.end(); 
        }

        size_t size() const {
            return buffer.size();
        }

        std::vector<int> const& operator[](int index) {
            return buffer.at(index);
        }

    private:
        void throwIfNullFileStream() {
            if (!fileStream) {
                throw std::runtime_error("Map::create - fail to load: media/map/Map.txt");
            }
        }

        void fillBufferFromFileStream() {
            for (std::string line; std::getline(fileStream, line);) {
                buffer.emplace_back(std::vector<int>());
                std::stringstream lineStream(line);
                std::move(std::istream_iterator<int>(lineStream), std::istream_iterator<int>(), std::back_inserter(buffer.back()));
            }
        }
    private:
        std::vector< std::vector<T> > buffer;
        std::ifstream fileStream;
    };

}

#endif /* FILESTREAMREADER_H */
