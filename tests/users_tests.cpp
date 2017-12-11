/** 
 * \file  users_tests.h
 * \brief Test file for users
 *
 * \version 0.0.3
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

// tested classes
#include "admin.h"
#include "person.h"
#include "student.h"
#include "teacher.h"

// test lib
#include <gtest/gtest.h>


char holder[] = "generic" ;
int  rights   = 0 ;


TEST(AdminStatus, UserStatus) {
    Person *p = new Admin(holder, holder, rights) ;

    ASSERT_STREQ("Admin", p->get_status) ;   
    ASSERT_STREQ((char*)user_status::admin, p->get_status) ;   
}

TEST(TeacherStatus, UserStatus) {
    Person *p = new Teacher(holder, holder, rights) ;

    ASSERT_STREQ("Teacher", p->get_status) ;   
    ASSERT_STREQ((char*)user_status::teacher, p->get_status) ;
}

TEST(StudentStatus, UserStatus) {
    Person *p = new Student(holder, holder, rights) ;

    ASSERT_STREQ("Student", p->get_status) ;   
    ASSERT_STREQ((char*)user_status::student, p->get_status) ;
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}