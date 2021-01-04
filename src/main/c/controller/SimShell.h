//
// Created by Administrator on 2021/1/4.
//

#ifndef MI6SIMSHELL4WINDOWS_SIMSHELL_H
#define MI6SIMSHELL4WINDOWS_SIMSHELL_H

#define USER_NAME_LEN 20
#define USER_PASSWORD_LEN 8
#define COURSE_NUM 3

#define ERROR_MESSAGE "输入有误!\n请随意按一个键继续!"
#define WELCOME_MESSAGE "welcome to SimShell\n请选择您的身份:\n\n[0] 教师\n[1] 学生\n[2] 退出\n\n"


enum
{
    ADMIN, GUEST
};


typedef struct user
{
    char username[USER_NAME_LEN + 1];
    char userPassword[USER_PASSWORD_LEN + 1];
    int usersLimit;
    struct user *next;
} USER_ACCOUNT, *pUSER_ACCOUNT;


typedef struct course
{
    int courseId;
    double courseScore;
} COURSE, *pCOURSE;


typedef struct student
{
    int stuId;
    char stuName[USER_NAME_LEN + 1];
    COURSE course[COURSE_NUM];
    struct student *next;
} STUDENT, *pSTUDENT;


void systemInit(pUSER_ACCOUNT *userList, pSTUDENT *stuList, char *str1, char *str2);

void welcomeMenu();

void getPassword(char *password);

int checkUserAccount(pUSER_ACCOUNT, USER_ACCOUNT);

void adminAccount(pUSER_ACCOUNT *, pSTUDENT *, char *, char *);

void guestAccount(pSTUDENT);

void adminInterfaceInit();

void searchStudentInformation(pSTUDENT, int);

void searchMenu(int);

void selectStudentWhereIdEqualsTo(pSTUDENT);

void insertIntoStudentsValue(pSTUDENT *, char *);

void updateStudentDatabase(pSTUDENT *, char *);

void updateStudentInformation(pSTUDENT *, char *);

void deleteStudentInformation(pSTUDENT *, char *);

void selectUserAccountWhereUserAccountEqualsTo(pUSER_ACCOUNT);

void selectAccountInit();

void selectAllFromUser(pUSER_ACCOUNT);

void selectUserWhereUserlevelEqualsTo(pUSER_ACCOUNT);

void selectUserWhereUsernameEqualsTo(pUSER_ACCOUNT);

void insertIntoUserAccountValue(pUSER_ACCOUNT *, char *);

void updateUserAccountWhereUserEqualsTo(pUSER_ACCOUNT *, char *);

void updateUserdatabase(pUSER_ACCOUNT *, char *);

void deleteFromUserAccountWhereUserEqualsTo(pUSER_ACCOUNT *, char *);

void guestInterfaceInit();

void selectStudentWhereNameEqualsTo(pSTUDENT);

void selectAllFromStudents(pSTUDENT);

void systemExit();


#endif //MI6SIMSHELL4WINDOWS_SIMSHELL_H
