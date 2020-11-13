#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    bool isVoted[10] = {
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false};

    char candidates[3][10] = {
        "BJP",
        "Congress",
        "NCP"};

    int votes[3] = {0, 0, 0};

    char users[10][10] = {
        "sweety",
        "saqeeb",
        "pratham",
        "siddhesh",
        "suraj",
        "dhiraj",
        "divya",
        "pooja",
        "sakshi",
        "chaitrali"};

    char passwords[10][15] = {
        "abcd",
        "saq@123",
        "prath@123",
        "sid@123",
        "suraj@123",
        "dhiraj@123",
        "divya@123",
        "pooja@123",
        "sakshi@123",
        "chait@123"};

    int choice1, choice2, choice3;
    char userName[10];
    char password[15];
    bool userFound = false;
    char adminId[10] = "superuser";
    char adminPass[15] = "super@123";
    int voteIndex;
    int maxVotes = 0;

    printf("==============================================\n");
    printf("***************Election System****************\n");

userSelection:

    printf("==============================================\n");
    printf("Enter your role: \n1.Voter\n2.Admin\n3.Exit\n");
    printf("----------------------------------------------\n");
    scanf("%d", &choice1);

    switch (choice1)
    {
    case 1:
        printf("Enter user ID: ");
        scanf("%s", &userName);
        printf("Enter password: ");
        scanf("%s", &password);

        //check user is there in
        for (int i = 0; i < 10; i++)
        {
            if ((strcmp(userName, users[i]) == 0) && (strcmp(password, passwords[i]) == 0))
            {
                if (isVoted[i])
                {
                    ("----------------------------------------------\n");
                    printf("!!!!!!!!You have already voted.!!!!!!!!!\n");
                    ("----------------------------------------------\n");
                    goto userSelection;
                }
                printf("----------------------------------------------\n");
                printf("Please select the canditate from below list to vote them.\n1.BJP\n2.Congress\n3.NCP\n");
                printf("----------------------------------------------\n");
                scanf("%d", &choice2);

                switch (choice2)
                {
                case 1:
                    votes[0] = votes[0] + 1;
                    break;
                case 2:
                    votes[1] = votes[1] + 1;
                    break;
                case 3:
                    votes[2] = votes[2] + 1;
                    break;
                default:
                    ("----------------------------------------------\n");
                    printf("!!!!!!!!!!!!!!!!!Wrong input!!!!!!!!!!!!!!!!!\n");
                    ("----------------------------------------------\n");
                    goto userSelection;
                }
                userFound = true;
                isVoted[i] = true;
                printf("Thanks for Voting...\n");
                printf("----------------------------------------------\n");
                printf("\n");
                goto userSelection;
            }
        }
        if (!userFound)
        {
            printf("----------------------------------------------\n");
            printf("!!!!!!!!!!!!!!!!!!Please enter correct username and password!!!!!!!!!!!!!!!!!!\n");
            printf("----------------------------------------------\n");
            goto userSelection;
        }
        break;

    case 2:
        printf("Enter admin ID: ");
        scanf("%s", &userName);
        printf("Enter admin password: ");
        scanf("%s", &password);

        if ((strcmp(userName, adminId) == 0) && (strcmp(password, adminPass) == 0))
        {
            printf("----------------------------------------------\n");
            printf("Select the Correct option.\n1.Status\n2.Results\n");
            printf("----------------------------------------------\n");
            scanf("%d", &choice3);

            switch (choice3)
            {
            case 1:
                printf("----------------------------------------------\n");
                for (int i = 0; i < 3; i++)
                {
                    printf("Candidates = %s \t Votes=%d\n", candidates + i, votes[i]);
                }
                printf("----------------------------------------------\n");
                goto userSelection;
                break;

            case 2:
                //search for highest votes
                for (int i = 0; i < 3; i++)
                {
                    if (votes[i] > maxVotes)
                    {
                        maxVotes = votes[i];
                        voteIndex = i;
                    }
                }

                printf("----------------------------------------------\n");
                printf("%s Won with %d votes\n", candidates[voteIndex], votes[voteIndex]);
                printf("----------------------------------------------\n");
                goto userSelection;
                break;

            default:
                ("----------------------------------------------\n");
                printf("!!!!!!!!!!!!!!!!!Wrong input!!!!!!!!!!!!!!!!!\n");
                ("----------------------------------------------\n");
                goto userSelection;
            }
        }
        else
        {
            printf("----------------------------------------------\n");
            printf("!!!!!!!!!!!!!!!!!!Please enter correct username and password!!!!!!!!!!!!!!!!!!\n");
            printf("----------------------------------------------\n");
            goto userSelection;
        }

    case 3:
        return 0;
    default:
        ("----------------------------------------------\n");
        printf("!!!!!!!!!!!!!!!!!Wrong input!!!!!!!!!!!!!!!!!\n");
        ("----------------------------------------------\n");
        goto userSelection;
    }
}
