#include <iostream>
#include <utility>

class Resource
{
public:
    Resource(int value)
        : data(new int(value))
    {
        std::cout << "Constructor\n";
    }

    Resource(const Resource& other)
    {
        data = new int(*other.data);
    }

    Resource& operator=(const Resource& other)
    {
        if (this != &other)
        {
            *data = *other.data;
        }

        return *this;
    }

    Resource(Resource&& other) noexcept
    {
        data = other.data;

        other.data = nullptr;
    }

    Resource& operator=(Resource&& other) noexcept
    {
        if (this != &other)
        {
            delete data;

            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    ~Resource()
    {
        delete data;
    }

private:
    int* data;
};






int main()
{
    Resource a(10);

    // Copy Constructor
    Resource b = a; 

    // Move Constructor
    Resource c = std::move(a);
    
    Resource d(20);

    // Copy Assignment
    d = b;

    // Move Assignment
    d = std::move(c);
}