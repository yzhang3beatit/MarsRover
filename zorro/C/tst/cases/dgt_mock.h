/*
 * DGTMock.h
 *
 */

#ifndef DGT_MOCK_H_
#define DGT_MOCK_H_


#include "gmock/gmock.h"
#include "mysack.h"
#include "dgtcm0gx.cpd"



class DGTMock
{
public:
    static DGTMock* getInstance(){
        if(instance == NULL){
            instance = new DGTMock();
        }
        return instance;
    }
    static void destroyInstance(){
        if(instance)
        {
            delete instance;
            instance = NULL;
        }
    }

    MOCK_METHOD2(unit_existence, unit_type_t(unit_type_t ut, unit_index_t ui));
    MOCK_METHOD1(unit_state_by_mb, unit_state_t(unit_address_t	mb_addres));

protected:
    static DGTMock* instance;
};

#define dgt_mock_instance (*DGTMock::getInstance())

#endif /* DGTMock_H_ */
