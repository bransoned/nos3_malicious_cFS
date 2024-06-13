#include <ItcLogger/Logger.hpp>
#include <echo_data_point.hpp>

namespace Nos3
{
    extern ItcLogger::Logger *sim_logger;

    EchoDataPoint::EchoDataPoint(double count)
    {
        sim_logger->trace("EchoDataPoint::EchoDataPoint:  Defined Constructor executed");

        /* Do calculations based on provided data - also preparing like ADC data to checkout is obvious */
        _42_parsing = false;
        _echo_data_is_valid = true;
        _echo_data[0] = (((count * 1) / 32767.0) - 32768.0);
        _echo_data[1] = (((count * 2) / 32767.0) - 32768.0);
        _echo_data[2] = (((count * 3) / 32767.0) - 32768.0);
    }

    EchoDataPoint::EchoDataPoint(int16_t spacecraft, const boost::shared_ptr<Sim42DataPoint> dp) : _dp(*dp), _sc(spacecraft)
    {
        sim_logger->trace("EchoDataPoint::EchoDataPoint:  42 Constructor executed");

        /* Initialize data */
        _42_parsing = true;
        _echo_data_is_valid = false;
        _echo_data[0] = _echo_data[1] = _echo_data[2] = 0.0;
    }
    
    void EchoDataPoint::do_parsing(void) const
    {
        if (_42_parsing)
        {
            try {
                /*
                ** Declare 42 telemetry string prefix
                ** 42 variables defined in `42/Include/42types.h`
                ** 42 data stream defined in `42/Source/IPC/SimWriteToSocket.c`
                */
                std::string key;
                key.append("SC[").append(std::to_string(_sc)).append("].svb"); // SC[N].svb

                /* Parse 42 telemetry */
                std::string values = _dp.get_value_for_key(key);

                std::vector<double> data;
                data.reserve(3);
                parse_double_vector(values, data);

                _echo_data[0] = data[0];
                _echo_data[1] = data[1];
                _echo_data[2] = data[2];

                /* Mark data as valid */
                _echo_data_is_valid = true;

                _not_parsed = false;

                /* Debug print */
                sim_logger->trace("EchoDataPoint::EchoDataPoint:  Parsed svb = %f %f %f", _echo_data[0], _echo_data[1], _echo_data[2]);
            } catch (const std::exception &e) {
                sim_logger->error("EchoDataPoint::EchoDataPoint:  Error parsing svb.  Error=%s", e.what());
            }
        }
    }

    /* Used for printing a representation of the data point */
    std::string EchoDataPoint::to_string(void) const
    {
        sim_logger->trace("EchoDataPoint::to_string:  Executed");
        
        std::stringstream ss;

        ss << std::fixed << std::setfill(' ');
        ss << "Echo Data Point:   Valid: ";
        ss << (_echo_data_is_valid ? "Valid" : "INVALID");
        ss << std::setprecision(std::numeric_limits<double>::digits10); /* Full double precision */
        ss << " Echo Data: "
           << _echo_data[0]
           << " "
           << _echo_data[1]
           << " "
           << _echo_data[2];

        return ss.str();
    }
} /* namespace Nos3 */
