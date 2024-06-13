#ifndef NOS3_ECHODATAPOINT_HPP
#define NOS3_ECHODATAPOINT_HPP

#include <boost/shared_ptr.hpp>
#include <sim_42data_point.hpp>

namespace Nos3
{
    /* Standard for a data point used transfer data between a data provider and a hardware model */
    class EchoDataPoint : public Sim42DataPoint
    {
    public:
        /* Constructors */
        EchoDataPoint(double count);
        EchoDataPoint(int16_t spacecraft, const boost::shared_ptr<Sim42DataPoint> dp);

        /* Accessors */
        /* Provide the hardware model a way to get the specific data out of the data point */
        std::string to_string(void) const;
        double      get_echo_data_x(void) const {parse_data_point(); return _echo_data[0];}
        double      get_echo_data_y(void) const {parse_data_point(); return _echo_data[1];}
        double      get_echo_data_z(void) const {parse_data_point(); return _echo_data[2];}
        bool        is_echo_data_valid(void) const {parse_data_point(); return _echo_data_is_valid;}
    
    private:
        /* Disallow these */
        EchoDataPoint(void) {};
        EchoDataPoint(const EchoDataPoint& sdp) : Sim42DataPoint(sdp) {};
        ~EchoDataPoint(void) {};

        // Private mutators
        inline void parse_data_point(void) const {if (_not_parsed) do_parsing();}
        void do_parsing(void) const;

        mutable Sim42DataPoint _dp;
        int16_t _sc;
        // mutable below so parsing can be on demand:
        mutable bool _42_parsing;
        mutable bool _not_parsed;
        /* Specific data you need to get from the data provider to the hardware model */
        /* You only get to this data through the accessors above */
        mutable bool   _echo_data_is_valid;
        mutable double _echo_data[3];
    };
}

#endif
