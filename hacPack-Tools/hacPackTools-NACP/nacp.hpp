#ifndef HPTNACP_NACP_H
#define HPTNACP_NACP_H

#include <string>
#include <cstdint>

#pragma pack(push, 1)
typedef struct {
    char Name[0x200];
    char Publisher[0x100];
} nacp_application_title_t;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
    nacp_application_title_t Title[0x10];
    char Isbn[0x25];
    std::uint8_t StartupUserAccount;
    std::uint8_t UserAccountSwitchLock;
    std::uint8_t AddOnContentRegistrationType;
    std::uint32_t AttributeFlag;
    std::uint32_t SupportedLanguageFlag;
    std::uint32_t ParentalControlFlag;
    std::uint8_t Screenshot;
    std::uint8_t VideoCapture;
    std::uint8_t DataLossConfirmation;
    std::uint8_t PlayLogPolicy;
    std::uint64_t PresenceGroupId;
    std::uint8_t RatingAge[0x20];
    char DisplayVersion[0x10];
    std::uint64_t AddOnContentBaseId;
    std::uint64_t SaveDataOwnerId;
    std::uint64_t UserAccountSaveDataSize;
    std::uint64_t UserAccountSaveDataJournalSize;
    std::uint64_t DeviceSaveDataSize;
    std::uint64_t DeviceSaveDataJournalSize;
    std::uint64_t BcatDeliveryCacheStorageSize;
    char ApplicationErrorCodeCategory[0x8];
    std::uint64_t LocalCommunicationId[0x8];
    std::uint8_t LogoType;
    std::uint8_t LogoHandling;
    std::uint8_t RuntimeAddOnContentInstall;
    std::uint8_t _0x30F3[0x3];
    std::uint8_t CrashReport;
    std::uint8_t Hdcp;
    std::uint64_t SeedForPseudoDeviceId ;
    char BcatPassphrase[0x41];
    std::uint8_t StartupUserAccountOptionFlag;
    std::uint8_t ReservedForUserAccountSaveDataOperation[0x6];
    std::uint64_t UserAccountSaveDataSizeMax;
    std::uint64_t UserAccountSaveDataJournalSizeMax;
    std::uint64_t DeviceSaveDataSizeMax;
    std::uint64_t DeviceSaveDataJournalSizeMax;
    std::uint64_t TemporaryStorageSize;
    std::uint64_t CacheStorageSize;
    std::uint64_t CacheStorageJournalSize;
    std::uint64_t CacheStorageDataAndJournalSizeMax;
    std::uint16_t CacheStorageIndexMax;
    std::uint8_t reserved_0x318a[0x6];
    std::uint64_t PlayLogQueryableApplicationId[0x10];
    std::uint8_t PlayLogQueryCapability;
    std::uint8_t RepairFlag;
    std::uint8_t ProgramIndex;
    std::uint8_t RequiredNetworkServiceLicenseOnLaunchFlag;
    std::uint8_t reserved_0x3214[0x4];
    std::uint8_t Reserved[0xDE8];
} nacp_t;
#pragma pack(pop)

class nacp_tool {
    public:
    void print(const std::string *input_filepath);
    void createxml(const std::string *input_filepath, const std::string *output_filepath);
    void createnacp(const std::string *input_filepath, const std::string *output_filepath);

    private:
    // Print, Extract
    const char* get_title_lang_name(int lang_id);
    const char* get_startup_user_account(uint8_t value);
    const char* get_attribute_flag(uint32_t flag);
    const char* get_parental_control_flag(uint32_t flag);
    const char* get_screenshot(uint8_t value);
    const char* get_videocapture(uint8_t value);
    const char* get_dataloss_confirmation(uint8_t value);
    const char* get_play_log_policy(uint8_t value);
    const char* get_rating_age_organization_name(int org_id);
    const char* get_logo_type(uint8_t value);
    const char* get_logo_handling(uint8_t value);
    const char* get_runtime_addoncontent_install(uint8_t value);
    const char* get_crash_report(uint8_t value);
    const char* get_hdcp(uint8_t value);
    const char* get_play_log_query_capability(uint8_t value);
    const char* get_repair_flag(uint8_t value);
    const char* get_addoncontent_registration_type(uint8_t value);
    const char *get_useraccount_switch_lock(uint8_t value);
    const char *get_required_network_service_license_on_launch(uint8_t value);
    const char *get_startup_user_account_option_flag(uint8_t value);
    // Create
    int get_title_lang_id(const char *lang_name);
    uint8_t set_startup_user_account(const char *value);
    uint32_t set_parental_control_flag(const char *flag);
    uint8_t set_screenshot(const char *value);
    uint8_t set_videocapture(const char *value);
    int get_rating_age_organization_id(const char *org_name);
    uint8_t set_dataloss_confirmation(const char *value);
    uint8_t set_play_log_policy(const char *value);
    uint8_t set_logo_type(const char *value);
    uint8_t set_logo_handling(const char *value);
    uint8_t set_addoncontent_registration_type(const char *value);
    uint8_t set_hdcp(const char *value);
    uint8_t set_crash_report(const char *value);
    uint8_t set_runtime_addoncontent_install(const char *value);
    uint8_t set_play_log_query_capability(const char *value);
    uint8_t set_repair_flag(const char *value);
    uint32_t set_attribute_flag(const char *value);
    uint8_t set_useraccount_switch_lock(const char *value);
    uint8_t set_required_network_service_license_on_launch(const char *value);
    uint8_t set_startup_user_account_option_flag(const char *value);
};

#endif
