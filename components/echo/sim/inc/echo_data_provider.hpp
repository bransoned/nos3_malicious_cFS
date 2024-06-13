#ifndef NOS3_ECHODATAPROVIDER_HPP
#define NOS3_ECHODATAPROVIDER_HPP

#include <boost/property_tree/xml_parser.hpp>
#include <ItcLogger/Logger.hpp>
#include <echo_data_point.hpp>
#include <sim_i_data_provider.hpp>

namespace Nos3
{
    class EchoDataProvider : public SimIDataProvider
    {
    public:
        /* Constructors */
        EchoDataProvider(const boost::property_tree::ptree& config);

        /* Accessors */
        boost::shared_ptr<SimIDataPoint> get_data_point(void) const;

    private:
        /* Disallow these */
        ~EchoDataProvider(void) {};
        EchoDataProvider& operator=(const EchoDataProvider&) {return *this;};

        mutable double _request_count;
    };
}

#endif
