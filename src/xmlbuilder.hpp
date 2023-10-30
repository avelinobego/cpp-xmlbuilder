#pragma once

#include <string>
#include <memory>
#include <vector>
#include <map>

namespace xml
{

    class element;

    using pointer = std::shared_ptr<element>;
    pointer make(std::string);

    using attribs = std::map<std::string,std::string>;

    class element final : public std::enable_shared_from_this<element>
    {

    private:
        element(){};
        void do_copy(pointer element);
        std::string open_tag(attribs attr);
        std::string close_tag();
        std::vector<pointer> elements;


    public:
        std::string name;
        std::string value;
        attribs attrs; 
        friend pointer make(std::string);
        pointer add(const pointer);
        void to_xml();
    };

}
