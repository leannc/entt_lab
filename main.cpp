
#include "UseCase.h"



void header(const std::string title)
{
    std::cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
    std::cout<<"START  "<<title<<std::endl;
    std::cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
}

void footer(const std::string title)
{
    std::cout<<"-------------------------------------------------"<<std::endl;
    std::cout<<"END  "<<title<<std::endl;
    std::cout<<"-------------------------------------------------"<<std::endl;
    std::cout<<std::endl;
}

#define CALL_USE_CASE(func) \
    header(#func);\
    func();\
    footer(#func);

int main() {

//    CALL_USE_CASE(use_case_std_any);
//    CALL_USE_CASE(use_case_entt_any);
//    CALL_USE_CASE(use_case_enum_as_bitmask);
//    CALL_USE_CASE(use_case_const_expr);
//    CALL_USE_CASE(use_case_hashed_string);
//    CALL_USE_CASE(use_case_type_xx);
//    CALL_USE_CASE(use_case_entt_tag);
//
//    CALL_USE_CASE(use_case_registry_version);
//    CALL_USE_CASE(use_case_registry_add_component);
//    CALL_USE_CASE(use_case_registry_observe_changes);
//    CALL_USE_CASE(use_case_registry_observer);
//    CALL_USE_CASE(use_case_registry_helpers);
//    CALL_USE_CASE(use_case_registry_organizer);
//    CALL_USE_CASE(use_case_registry_ctx_variables);
//    CALL_USE_CASE(use_case_registry_snapshot_for_serialization);
    CALL_USE_CASE(use_case_registry_group);
//    CALL_USE_CASE(use_case_registry_view);
    return 0;

}

