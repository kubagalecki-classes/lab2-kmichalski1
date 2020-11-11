#pragma once
#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* ptr;

public:  
    ResourceManager()
    { 
        ptr = new Resource; 
    }
    ResourceManager(const ResourceManager& res) : ptr(res.ptr) 
    {
        ptr = new Resource{ *res.ptr }; 
    }
    ResourceManager& operator=(const ResourceManager& res) 
    {
        if (ptr == res.ptr) return *this;
        delete ptr;
        ptr = new Resource{ *res.ptr };
        return *this;
    }
    ResourceManager(ResourceManager&& res) 
    {
        ptr = res.ptr;
        res.ptr = nullptr;
    }
    ResourceManager& operator=(ResourceManager&& res) 
    {
        if (ptr == res.ptr) return *this;
        delete ptr;
        ptr = res.ptr;
        res.ptr = nullptr;
        return *this;
    }
    double get() 
    { 
        return ptr->get(); 
    }
    ~ResourceManager()
    { 
        delete ptr; 
    }
};
