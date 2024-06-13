#include <echo_data_provider.hpp>

namespace Nos3
{
    REGISTER_DATA_PROVIDER(EchoDataProvider,"ECHO_PROVIDER");

    extern ItcLogger::Logger *sim_logger;

    EchoDataProvider::EchoDataProvider(const boost::property_tree::ptree& config) : SimIDataProvider(config)
    {
        sim_logger->trace("EchoDataProvider::EchoDataProvider:  Constructor executed");
        _request_count = 0;
    }

    boost::shared_ptr<SimIDataPoint> EchoDataProvider::get_data_point(void) const
    {
        sim_logger->trace("EchoDataProvider::get_data_point:  Executed");

        /* Prepare the provider data */
        _request_count++;

        /* Request a data point */
        SimIDataPoint *dp = new EchoDataPoint(_request_count);

        /* Return the data point */
        return boost::shared_ptr<SimIDataPoint>(dp);
    }
}
