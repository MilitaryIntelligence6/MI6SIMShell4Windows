#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "controller/SimShell.h"

#define CONFIG_PATH "./resources/properties/configure.cfg"
#define READ_CONFIG_FAILED 3


int main()
{
    char str[1024] = "";
    char str1[1024] = "";
    char str2[1024] = "";
    FILE *fp = fopen(CONFIG_PATH, "r");

    if (!fp)
    {
        printf("读取config文件%s错误! 请改变定义config路径或者填充config!", CONFIG_PATH);
        exit(READ_CONFIG_FAILED);
    }

    USER_ACCOUNT *user_list = NULL;
    STUDENT *stu_list = NULL;
    int button;
    USER_ACCOUNT user;
    memset(&user, 0, sizeof(USER_ACCOUNT));

    fgets(str, sizeof(str) - 1, fp);
    strncpy(str1, str, strlen(str) - 1);  //去掉结尾换行
    memset(str, 0, sizeof(str));
    fgets(str, sizeof(str) - 1, fp);
    if (str[strlen(str)] == '\n')    //配置文件只读两行，判断第二行有没有换行在末尾
    {
        strncpy(str2, str, strlen(str) - 1);
    } else
    {
        strncpy(str2, str, strlen(str));
    }
    systemInit(&user_list, &stu_list, str1, str2);
    while (1)
    {
        system("cls");
        welcomeMenu();
        printf("select a number: ");
        button = getchar() - '0';
        if (2 == button)
        {
            systemExit();
            return 0;
        } else if (ADMIN == button || GUEST == button)
            user.usersLimit = button;
        else
        {
            fflush(stdin);
            printf("Input Error!\nPress any key to select again");
            _getch();
            continue;
        }
        system("cls");
        printf("Username:");
        scanf("%s", &user.username);
        printf("Password:");
        fflush(stdin);
        getPassword(user.userPassword);
        if (checkUserAccount(user_list, user))
        {
            if (user.usersLimit == ADMIN)
            {
                adminAccount(&user_list, &stu_list, str1, str2);
            } else if (user.usersLimit == GUEST)
            {
                guestAccount(stu_list);
            }
            break;
        } else
        {
            printf("\nNot Found!\n");
            fflush(stdin);
            printf(ERROR_MESSAGE);
            if (_getch() != 'y')
                break;
        }

    }
    return 0;
}