#include "xmlbuilder.hpp"

namespace xml
{

    pointer make(std::string _name)
    {
        auto temp = new xml::element;
        temp->name = _name;
        return pointer(temp);
    }

    pointer element::add(pointer e)
    {
        this->elements.push_back(e);
        return shared_from_this();
    }

    void element::to_xml()
    {
        this->value.clear();
        
        auto result = std::string{};

        result.append(this->open_tag(this->attrs));
        result.append(this->value);

        for (auto e : this->elements)
        {
            e->to_xml();
            result.append(e->value);
        }

        result.append(this->close_tag());

        this->value = result;

    }

    void element::do_copy(pointer e)
    {
        this->name = e->name;
    }

    std::string element::open_tag(attribs att)
    {
        std::string result;
        result.append("<");
        result.append(this->name);
        for (auto a : this->attrs)
        {
            result.append(" ");
            result.append(a.first);
            result.append("=\"");
            result.append(a.second);
            result.append("\"");
        }
        result.append(">");
        return result;
    }

    std::string element::close_tag()
    {
        return "</" + this->name + ">";
    }

}
