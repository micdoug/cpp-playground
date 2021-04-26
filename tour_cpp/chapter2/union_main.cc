#include <iostream>
#include <variant>
#include <string>
#include "absl/strings/str_format.h"

enum class Type
{
    ptr,
    num,
};

class Node
{
};

union Value
{
    Node *p;
    int i;
};

struct Entry
{
    std::string name;
    Type type;
    Value value;
};

std::ostream &operator<<(std::ostream &out, const Entry &entry)
{
    out << absl::StrFormat("Entry(name='%s', type=%s, value=%s)\n",
                           entry.name,
                           entry.type == Type::ptr ? "ptr" : "num",
                           entry.type == Type::ptr ? "Node()" : std::to_string(entry.value.i));
    return out;
}

struct NewEntry
{
    std::string name;
    std::variant<Node *, int> value;
};

std::ostream &operator<<(std::ostream &out, const NewEntry &entry)
{
    out << absl::StrFormat("NewEntry(name='%s', value=%s)\n",
                           entry.name,
                           std::holds_alternative<int>(entry.value) ? std::to_string(std::get<int>(entry.value)) : "Node()");
    return out;
}

int main()
{
    Entry entry{"num_entry", Type::num, {.i = 10}};
    Entry entry2{"ptr_entry", Type::ptr, {new Node}};
    std::cout << entry;
    std::cout << entry2;

    NewEntry new_entry {"num_entry", {42}};
    NewEntry new_entry2 {"ptr_entry", {new Node()}};

    std::cout << new_entry;
    std::cout << new_entry2;

    return 0;
}