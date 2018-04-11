#pragma once

#include "iqrf/DPAMessage.h"

namespace BeeeOn {

/**
 * @brief DPA request contains a header:
 *
 *  - NADR(2B) - network address
 *  - PNUM(1B)- peripherals number
 *  - CMD(1B) - command identification
 *  - HWPID(2B) - hw profile
 *  - PData - specific data
 */
class DPARequest : public DPAMessage {
public:
	typedef Poco::SharedPtr <DPARequest> Ptr;

	DPARequest();

	/**
	 * @brief Request with default HWPID and empty peripheral data.
	 */
	DPARequest(
		NetworkAddress node,
		uint8_t pNumber,
		uint8_t pCommand
	);

	DPARequest(
		NetworkAddress node,
		uint8_t pNumber,
		uint8_t pCommand,
		uint16_t hwPID,
		const std::vector<uint8_t> &peripheralData
	);

	std::string toDPAString() const override;

	/**
	* @brief Number of bytes in request.
	*/
	size_t size() const;
};

}
