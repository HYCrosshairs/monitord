#pragma once

namespace sys
{
enum class SensorError : int
{
    SENSORS_ERR_WILDCARDS	, /* Wildcard found in chip name */
    SENSORS_ERR_NO_ENTRY	, /* No such subfeature known */
    SENSORS_ERR_ACCESS_R	, /* Can't read */
    SENSORS_ERR_KERNEL	    , /* Kernel interface error */
    SENSORS_ERR_DIV_ZERO	, /* Divide by zero */
    SENSORS_ERR_CHIP_NAME	, /* Can't parse chip name */
    SENSORS_ERR_BUS_NAME	, /* Can't parse bus name */
    SENSORS_ERR_PARSE	    , /* General parse error */
    SENSORS_ERR_ACCESS_W	, /* Can't write */
    SENSORS_ERR_IO		    , /* I/O error */
    SENSORS_ERR_RECURSION	, /* Evaluation recurses too deep */
    
    SENSORS_ERR_MAX
};

} // namespace sys
