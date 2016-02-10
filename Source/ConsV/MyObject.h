#pragma once

#include <fstream>
#include <tuple>
using std::tuple;
using std::ostream;
using std::endl;

struct IObject
{
    IObject(tuple<int, int> in_location = tuple<int, int>(0, 0), uint numb = 0)
        : location(in_location), num_in_seg_array(numb)
    {}

    virtual ~IObject() {}
    virtual std::string Write() = 0;
    virtual uint IsGear() = 0;
    tuple<int, int> location;
    uint num_in_seg_array;
};

struct Gear
    : public IObject
{
    /// radius of the inscribed circle
    float min_r;
    /// radis of the circumscribed circle
    float max_r;
    /// is the gear is broken?
    bool is_broken;
    /// number of cogs
    int num_cogs;

    Gear(tuple<int, int> in_location = tuple<int, int>(0, 0), float in_min_r = 0,
        float in_max_r = 0, bool in_is_broken = true, int in_num_cogs = 0, uint numb = 0)
        : IObject(in_location, numb), min_r(in_min_r), max_r(in_max_r),
        is_broken(in_is_broken), num_cogs(in_num_cogs)
    {}
    uint IsGear(){
        return 1;
    }
    std::string Write()
    {
        int x, y;
        std::tie(x, y) = location;
        std::string x_str = std::to_string(x);
        std::string y_str = std::to_string(y);
        std::string min_r_str = std::to_string(min_r);
        std::string max_r_str = std::to_string(max_r);
        std::string num_cogs_str = std::to_string(num_cogs);
        std::string is_br_str = (is_broken ? "true" : "false");
        std::string out = "Gear";
        out +=  + " " + x_str + " " + y_str + " " + max_r_str + " " + min_r_str + " " + is_br_str + " " + num_cogs_str + "\n";
        return out;
    }
};

struct Axis
    : public IObject
{
    Axis(tuple<int, int> in_location = tuple<int, int>(0, 0), uint numb = 0)
        : IObject(in_location, numb)
    {}
    uint IsGear(){
        return 0;
    }
    std::string Write()
    {
        int x, y;
        std::tie(x, y) = location;
        std::string x_str = std::to_string(x);
        std::string y_str = std::to_string(y);
        std::string out = "Axis";
        out +=  " " + x_str + " " + y_str + "\n";
        return out;
    }
};
