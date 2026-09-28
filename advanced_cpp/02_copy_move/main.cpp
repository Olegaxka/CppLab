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
        : data(new int(*other.data))
    {
        std::cout << "Copy constructor\n";
    }

    Resource& operator=(const Resource& other)
    {
        if (this != &other)
        {
            *data = *other.data;
        }

        std::cout << "Copy assignment\n";

        return *this;
    }

    Resource(Resource&& other) noexcept
        : data(other.data)
    {
        other.data = nullptr;

        std::cout << "Move constructor\n";
    }

    Resource& operator=(Resource&& other) noexcept
    {
        if (this != &other)
        {
            delete data;

            data = other.data;
            other.data = nullptr;
        }

        std::cout << "Move assignment\n";

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
	Resource a{10};

	Resource b = a;

	Resource c(20);

	c = a;

	Resource d = std::move(a);

	Resource e(30);

	e = std::move(d);
}