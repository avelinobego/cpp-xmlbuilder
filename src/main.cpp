#include <iostream>
#include "xmlbuilder.hpp"

int main(int argc, char const *argv[])
{

    std::cout << "Teste de XML\n";

    auto a = xml::make("A");
    auto b = xml::make("B");
    auto c = xml::make("C");

    for (auto i = 0; i < 1000; i++)
    {
        auto d = xml::make("D");
        auto e = xml::make("E");

        d->attrs.emplace("id", std::to_string(i));
        d->attrs.emplace("nome", "Bego");

        e->value.append(std::to_string(i));

        c->add(d->add(e));
    }

    a->add(b);
    b->add(c);

    a->to_xml();

    std::cout << a->value << '\n';

    return 0;
}
