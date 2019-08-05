#ifndef STM32_LIB_USB_H_
#define STM32_LIB_USB_H_

#include <stdint.h>

#pragma pack(push, 1)

typedef uint8_t UsbIndex;

/**
	USB Setup Packet
*/

typedef struct UsbPacketSetup UsbPacketSetup;
struct UsbPacketSetup {
	struct {
		uint8_t recipient : 5;
		uint8_t type : 2;
		uint8_t direction : 1;
	} request_type;
	uint8_t request;
	uint16_t value;
	uint16_t index;
	uint16_t length;
};

typedef enum UsbRequestDirection UsbRequestDirection;
enum UsbRequestDirection {
	USB_REQUEST_DIRECTION_HOST_TO_DEVICE,
	USB_REQUEST_DIRECTION_DEVICE_TO_HOST,
};

typedef enum UsbRequestType UsbRequestType;
enum UsbRequestType {
	USB_REQUEST_TYPE_STANDARD,
	USB_REQUEST_TYPE_CLASS,
	USB_REQUEST_TYPE_VENDOR,
};

typedef enum UsbRequestRecipient UsbRequestRecipient;
enum UsbRequestRecipient {
	USB_REQUEST_RECIPIENT_DEVICE,
	USB_REQUEST_RECIPIENT_INTERFACE,
	USB_REQUEST_RECIPIENT_ENDPOINT,
	USB_REQUEST_RECIPIENT_OTHER,
};

typedef enum UsbRequest UsbRequest;
enum UsbRequest {
	USB_REQUEST_GET_STATUS,
	USB_REQUEST_CLEAR_FEATURE,
	USB_REQUEST_SET_FEATURE = 3,
	USB_REQUEST_SET_ADDRESS = 5,
	USB_REQUEST_GET_DESCRIPTOR,
	USB_REQUEST_SET_DESCRIPTOR,
	USB_REQUEST_GET_CONFIGURATION,
	USB_REQUEST_SET_CONFIGURATION,
	USB_REQUEST_GET_INTERFACE,
	USB_REQUEST_SET_INTERFACE,
	USB_REQUEST_SYNC_FRAME,
};

/**
	USB Descriptors
*/

typedef enum UsbDescriptorType UsbDescriptorType;
enum UsbDescriptorType {
	USB_DESCRIPTOR_TYPE_DEVICE = 1,
	USB_DESCRIPTOR_TYPE_CONFIGURATION,
	USB_DESCRIPTOR_TYPE_STRING,
	USB_DESCRIPTOR_TYPE_INTERFACE,
	USB_DESCRIPTOR_TYPE_ENDPOINT,
	USB_DESCRIPTOR_TYPE_DEVICE_QUALIFIER,
	USB_DESCRIPTOR_TYPE_DEVICE_SPEED_CONFIGURATION,
	USB_DESCRIPTOR_TYPE_INTERFACE_POWER,
	USB_DESCRIPTOR_TYPE_OTG,
};

typedef struct UsbDescriptorDevice UsbDescriptorDevice;
struct UsbDescriptorDevice {
	uint8_t length;
	uint8_t descriptor_type;
	
	uint16_t usb_version;
	uint8_t device_class;
	uint8_t device_sub_class;
	uint8_t device_protocol;
	uint8_t max_packet_size_ep0;
	uint16_t vendor_id;
	uint16_t product_id;
	uint16_t device_release;
	UsbIndex manufacturer;
	UsbIndex product;
	UsbIndex serial_number;
	uint8_t num_configurations;
};

typedef struct UsbDescriptorConfiguration UsbDescriptorConfiguration;
struct UsbDescriptorConfiguration {
	uint8_t length;
	uint8_t descriptor_type;
	
	uint16_t total_length;
	uint8_t num_interfaces;
	uint8_t configuration_value;
	UsbIndex configuration;
	struct {
		uint8_t : 5;	
		uint8_t remote_wakeup : 1;
		uint8_t self_powered : 1;
		uint8_t one : 1;
	};
	uint8_t max_power;
};

typedef struct UsbDescriptorInterface UsbDescriptorInterface;
struct UsbDescriptorInterface {
	uint8_t length;
	uint8_t descriptor_type;
	
	uint8_t interface_number;
	uint8_t alternate_setting;
	uint8_t num_endpoints;
	uint8_t interface_class;
	uint8_t interface_sub_class;
	uint8_t interface_protocol;
	UsbIndex interface;
};

typedef struct UsbDescriptorEndpoint UsbDescriptorEndpoint;
struct UsbDescriptorEndpoint {
	uint8_t length;
	uint8_t descriptor_type;
	
	struct {
		uint8_t endpoint_number : 4;
		uint8_t : 3;
		uint8_t direction : 1;
	} endpoint_address;
	
	struct {
		uint8_t transfer_type : 2;
		uint8_t synchronisation_type : 2;
		uint8_t usage_type : 2;
		uint8_t : 2;
	} attributes;
	
	uint16_t max_packet_size;
	uint8_t interval;
};

typedef struct UsbDescriptorString UsbDescriptorString;
struct UsbDescriptorString {
	uint8_t length;
	uint8_t descriptor_type;
	uint16_t string[];
};

typedef union UsbDescriptor UsbDescriptor;
union UsbDescriptor {
	struct {
		uint8_t length;
		uint8_t descriptor_type;
	} common;
	
	UsbDescriptorDevice device;
	UsbDescriptorConfiguration configuration;
	UsbDescriptorInterface interface;
	UsbDescriptorEndpoint endpoint;
	UsbDescriptorString string;
};

typedef enum UsbEndpointAttributeTransferType UsbEndpointAttributeTransferType;
enum UsbEndpointAttributeTransferType {
	USB_ENDPOINT_ATTRIBUTE_TRANSFER_TYPE_CONTROL,
	USB_ENDPOINT_ATTRIBUTE_TRANSFER_TYPE_ISOCHRONOUS,
	USB_ENDPOINT_ATTRIBUTE_TRANSFER_TYPE_BULK,
	USB_ENDPOINT_ATTRIBUTE_TRANSFER_TYPE_INTERRUPT,
};

typedef enum UsbEndpointAttributeSynchronisationType UsbEndpointAttributeSynchronisationType;
enum UsbEndpointAttributeSynchronisationType {
	USB_ENDPOINT_ATTRIBUTE_SYNCHRONISATION_TYPE_NONE,
	USB_ENDPOINT_ATTRIBUTE_SYNCHRONISATION_TYPE_ASYNCHRONOUS,
	USB_ENDPOINT_ATTRIBUTE_SYNCHRONISATION_TYPE_ADAPTIVE,
	USB_ENDPOINT_ATTRIBUTE_SYNCHRONISATION_TYPE_SYNCHRONOUS,
};

typedef enum UsbEndpointAttributeUsageType UsbEndpointAttributeUsageType;
enum UsbEndpointAttributeUsageType {
	USB_ENDPOINT_ATTRIBUTE_USAGE_TYPE_DATA_ENDPOINT,
	USB_ENDPOINT_ATTRIBUTE_USAGE_TYPE_FEEDBACK_ENDPOINT,
	USB_ENDPOINT_ATTRIBUTE_USAGE_TYPE_IMPLICIT_FEEDBACK_DATA_ENDPOINT,
};

typedef enum UsbClass UsbClass;
enum UsbClass {
	USB_CLASS_NONE,
	USB_CLASS_AUDIO,
	USB_CLASS_CDC_CONTROL,
	USB_CLASS_HID,
	USB_CLASS_PHYSICAL = 0x05,
	USB_CLASS_IMAGE,
	USB_CLASS_PRINTER,
	USB_CLASS_MASS_STORAGE,
	USB_CLASS_HUB,
	USB_CLASS_CDC_DATA,
	USB_CLASS_SMART_CARD,
	USB_CLASS_CONTENT_SECURITY = 0x0D,
	USB_CLASS_VIDEO,
	USB_CLASS_PERSONAL_HEALTHCARE,
	USB_CLASS_AUDIO_VIDEO,
	USB_CLASS_BILLBOARD,
	USB_CLASS_USB_C_BRIDGE,
	USB_CLASS_DIAGNOSTIC = 0xDC,
	USB_CLASS_WIRELESS_CONTROLLER = 0xE0,
	USB_CLASS_MISC = 0xEF,
	USB_CLASS_APP_SPECIFIC = 0xFE,
	USB_CLASS_VENDOR_SPECIFIC = 0xFF,
};

#pragma pack(pop)

#endif
