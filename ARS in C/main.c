#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int reservation();
int cancel();
int reschedule();
int oneWayReservation(FILE*ptr);
int returnTypeReservation(FILE*ptr);
void display();
int main() {
    FILE* ptr= fopen("reser.txt","a");
     if (ptr == NULL) {
        printf("Error opening the file for writing.\n");
        return 1;}
    int choice;
    printf("\n\n\t\t ********************************************************************");
    printf("\n\t\t            Welcome to Indian Airline System                   ");
    printf("\n\t\t   *******************************************************************");
    printf("\n\n\n\t\t Please enter your choice from below (1-5):");
    printf("\n\n\t\t 1. One-Way Flight");
    printf("\n\n\t\t 2. Return Type Flight");
    printf("\n\n\t\t 3. Cancel");
    printf("\n\n\t\t 4. Reschedule");
    printf("\n\n\t\t 5. Display Booked Flight");
    printf("\n\n\t\t 6. EXIT");


    printf("\n\n\t\t Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
		    oneWayReservation(ptr);
            // Call function for one-way flight reservation
            break;
        case 2:
            returnTypeReservation(ptr);
			// Call function for return type flight reservation
            break;
        case 3:
		    cancel();
            // Call function for cancellation
            break;
        case 4:
           reschedule();
		    // Call function for reschedule
            break;
        case 5:
		   display();
            // Call function for one-way flight reservation
            break;
        case 6:
            printf("\n Thank you for using Indian Airline System!\n");
            exit(0);
        default:
            printf("\n\n\t SORRY INVALID CHOICE!");
            printf("\n Thank you for using Indian Airline System!\n");
            exit(0);
    }

    return 0;
}

int oneWayReservation(FILE*ptr) 
{int choice, dd, mm, yyyy;
    int i, pass;
    char email[50], des[30], fname[50], lname[50];
    char class[30];
    char origin[50], destination[50];

while(1){
    printf("\n\tEnter your first name: ");
    scanf("%s", fname);
    printf("\n\tEnter your last name: ");
    scanf("%s", lname);

    printf("\n\tEnter your passport number: ");
        scanf("%d", &pass);

    printf("\n\tEnter your email address: ");
    scanf("%s", email);

    printf("\n\n\n\t\tPlease Enter which Class you want to travel (1-4):");
    printf("\n\n\t\t1. Economy Class");
    printf("\n\n\t\t2. Premium Economy Class");
    printf("\n\n\t\t3. Business Class");
    printf("\n\n\t\t4. First Class");
    co:{
    printf("\n\n\t\tEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            strcpy(class, "Economy Class");
            break;
        case 2:
            strcpy(class, "Premium Economy Class");
            break;
        case 3:
            strcpy(class, "Business Class");
            break;
        case 4:
            strcpy(class, "First Class");
            break;
        default:
            printf("\n\n\tSORRY INVALID CHOICE!");
            printf("\n\n\tPLEASE CHOOSE FROM 1-4");
            printf("\n\n\tDo not forget to choose from 1-4");
            goto co;}
    }

    printf("\nEnter the origin: ");
    scanf("%s", origin);
    printf("\nEnter the destination: ");
    scanf("%s", destination);

    printf("Enter the reservation date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &dd, &mm, &yyyy);

    time_t current_time;//used this function to campare reservation time with present time 
    struct tm *current_date;

    time(&current_time);
    current_date = localtime(&current_time);

    if (yyyy < current_date->tm_year + 1900 ||
        (yyyy == current_date->tm_year + 1900 && mm < current_date->tm_mon + 1) ||
        (yyyy == current_date->tm_year + 1900 && mm == current_date->tm_mon + 1 && dd < current_date->tm_mday)) {
         printf("\nInvalid date OR Flights are not available for this date\n");
         printf("\n Thank You");
        return 0; // Exit the function if past date
    }

    if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd == 31) {
        printf("Invalid date OR The flights are not available for this date.\n");
        return 0; // Exit the function for invalid date
    } else if (mm == 2 && (dd == 29 || dd == 30 || (dd == 28 && yyyy % 4 != 0))) {
        printf("Invalid date OR The flights are not available for this date.\n");
        return 0; // Exit the function for invalid date
    } else {
        printf("Flight available is: %02d/%02d/%04d\n", dd, mm, yyyy);
    }
int hour,minute,code1 ,num1[10],num2[10];
srand(time(0));//used this for getting random time
hour = rand()%24;
minute = rand()%60;    
int n1= rand()%10+1;  
 time_t t;   
   time(&t);                     
    code1 = (rand()%(99-10+1))+10;       
    char randomChar = 'A' + (rand() % 26);
    char randomChar1 = 'A' + (rand() % 6);
    char randomChar2 = 'A' + (rand() % 26);
    char randomChar3 = 'A' + (rand() % 26);
printf("at time : %d:%d \n ",hour,minute); 
 printf("\n\n\tFlight Ticket price is:\tINR ****%d",code1);    
       printf("\n\tEnter Payment Method");
    printf("\n\t1. Internet Banking ");
    printf("\n\t2. Card  ");
    printf("\n\t3. UPI  ");
    to:{
    printf("\n\n\t\tEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:printf("\nEnter the Bank account number: ");
    scanf("%s", num1);
    printf("\nEnter the OTP: ");
    scanf("%s", num2);
    printf("\nPayment Successfull ");
            break;
        case 2:
     printf("\nEnter the Card number: ");
    scanf("%s", num1);
    printf("\nEnter the OTP: ");
    scanf("%s", num2);
    printf("\nPayment Successfull ");
            break;       
            case 3:
         printf("\nEnter the UPI number: ");
    scanf("%d", num1);
    printf("\nEnter the OTP: ");
    scanf("%d", num2);
    printf("\nPayment Successfull ");
            break;        
            default:
            printf("\n\n\tSORRY INVALID CHOICE!");
            printf("\n\n\tPLEASE CHOOSE FROM 1-4");
            printf("\n\n\tDo not forget to choose from 1-4");
            goto to;}
    }    
      printf("\nYour PNR number is: \t%c%d%c%c%d%c%d",randomChar1,hour,randomChar2,randomChar,minute,randomChar3,n1); 
	int code ;
srand(time(0));
code = rand()%100;//used this for geeting random seat
printf("                                                                             \n");
printf("                                                                             \n");
printf("                                                                             \n");
printf("                                                                             \n");
printf("                                                                             \n");
	printf("                                                                             \n");
    printf("_\n");
	printf("\t\tIndian Airlines \t\t\tBoarding Pass \t\n");
	printf("_\n");
	 printf("\t\t\t%s\n", ctime(&t));
	printf("_\n");
	printf("\t\tName of passenger:%s %s\t\t\t\t\t\t\t\t\n",fname,lname);
      printf("\n\tPNR number is: \t%c%d%c%c%d%c%d\n",randomChar1,hour,randomChar2,randomChar,minute,randomChar3,n1); 
	printf("\t\tClass:%s\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n",class);
	printf("\t\t\tSeat:%c-%d \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n",randomChar1,code);
	printf("\t\t Date: %02d/%02d/%04d\t\t\t\t\t\t\t\n", dd, mm, yyyy);
	printf("\t\tFrom %s to %s\t\t\t\t\t\t\t\t\n",origin,destination);
	printf("\t\tTime: %d:%d \t\t\t\t\t\t\t\t\t\t\t\t\t\t\n",hour,minute);
	printf("\t\t\t\t\t \t \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n");
	printf("_\n");
      fprintf(ptr,"                                                                             \n");
    fprintf(ptr,"_\n");
	fprintf(ptr,"\t\tIndian Airlines \t\t\tBoarding Pass \t\n");
	fprintf(ptr,"_\n");
	fprintf(ptr,"\t\t\t%s\n", ctime(&t));
	fprintf(ptr,"_\n");
	fprintf(ptr,"\t\tName of passenger:%s %s\t\t\t\t\t\t\t\t\n",fname,lname);
     fprintf(ptr,"\n\tPNR number is: \t%c%d%c%c%d%c%d\n",randomChar1,hour,randomChar2,randomChar,minute,randomChar3,n1); 
	fprintf(ptr,"\t\tClass:%s\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n",class);
	fprintf(ptr,"\t\t\tSeat:%c-%d \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n",randomChar1, code);
	fprintf(ptr,"\t\t Date: %02d/%02d/%04d\t\t\t\t\t\t\t\n", dd, mm, yyyy);
	fprintf(ptr,"\t\tFrom %s to %s\t\t\t\t\t\t\t\t\n",origin,destination);
	fprintf(ptr,"\t\tTime: %d:%d \t\t\t\t\t\t\t\t\t\t\t\t\t\t\n",hour,minute);
	fprintf(ptr,"\t\t\t\t\t \t \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n");
    fprintf(ptr,"_\n");
	printf("\n\tAre you Want to Book an another Ticket");
	printf("\n\n\t\t 1. Yes");
		printf("\n\n\t\t 2. No");
		printf("\n\n\t\t Enter your choice :");
scanf("%d", &choice); 
		switch (choice)
		{
		case 1:
			break;
		case 2:
		printf("\n THANK YOU  ");
		printf("\n HAPPY JOURNEY");
        return 0;
			break;
			default:
			printf("\n\n\t SORRY INVALID CHOICE!");
			printf("\n THANK YOU  ");
		printf("\n HAPPY JOURNEY");
        fclose(ptr);
		return 0;	}}
        return 0;
}
int returnTypeReservation(FILE*ptr) {
    int i,choice, dd_out, mm_out, yyyy_out, dd_return, mm_return, yyyy_return, pass,num1[10],num2[10];
    char email[50], fname[50], lname[50],class[30],origin[50],destination[50];
    int hour1,minute1,hour2,minute2,code1,code2 ,code3;
    while(1){
    printf("\n\tEnter your first name: ");
    scanf("%s", fname);
    printf("\n\tEnter your last name: ");
    scanf("%s", lname);
    printf("\n\tEnter your passport number: ");
    scanf("%d", &pass);
    printf("\n\tEnter your email address: ");
    scanf("%s", email);
    printf("\n\n\n\t\tPlease enter your choice from below (1-4):");
    printf("\n\n\t\t1. Economy Class");
    printf("\n\n\t\t2. Premium Economy Class");
    printf("\n\n\t\t3. Business Class");
    printf("\n\n\t\t4. First Class");
    printf("\n\n\t\tEnter your choice: ");
    scanf("%d", &choice);
    co:{
    switch (choice) {
        case 1:
            strcpy(class, "Economy Class");
            break;
        case 2:
            strcpy(class, "Premium Economy Class");
            break;
        case 3:
            strcpy(class, "Business Class");
            break;
        case 4:
            strcpy(class, "First Class");
            break;
        default:
            printf("\n\n\tSORRY INVALID CHOICE!");
            printf("\n\n\tPLEASE CHOOSE FROM 1-4");
            printf("\n\n\tDo not forget to choose from 1-4");
            goto co;}
    }

    printf("\nEnter the origin: ");
    scanf("%s", origin);
    printf("\nEnter the destination: ");
    scanf("%s", destination);
    printf("Enter the departure date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &dd_out, &mm_out, &yyyy_out);
    time_t current_time;
    struct tm *current_date;

    time(&current_time);
    current_date = localtime(&current_time);

    if (yyyy_out < current_date->tm_year + 1900 ||
        (yyyy_out == current_date->tm_year + 1900 && mm_out < current_date->tm_mon + 1) ||
        (yyyy_out == current_date->tm_year + 1900 && mm_out == current_date->tm_mon + 1 && dd_out < current_date->tm_mday)) {
         printf("\nInvalid date OR Flights are not available for this date\n");
         printf("\n Thank You");
        return 0; // Exit the function if past date
    }

    if ((mm_out == 4 || mm_out == 6 || mm_out == 9 || mm_out == 11) && dd_out == 31) {
        printf("Invalid date OR The flights are not available for this date.\n");
        return 0; // Exit the function for invalid date
    } else if (mm_out == 2 && (dd_out == 29 || dd_out == 30 || (dd_out == 28 && yyyy_out % 4 != 0))) {
        printf("Invalid date OR The flights are not available for this date.\n");
         printf("\n Thank You");
        return 0; // Exit the function for invalid date
    } else { printf("Enter the return date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &dd_return, &mm_return, &yyyy_return);

    // Validate the return date
    if (yyyy_return < current_date->tm_year + 1900 ||
        (yyyy_return == current_date->tm_year + 1900 && mm_return < current_date->tm_mon + 1) ||
        (yyyy_return == current_date->tm_year + 1900 && mm_return == current_date->tm_mon + 1 && dd_return < current_date->tm_mday)) {
        printf("Sorry, past return dates are not allowed.\n");
         printf("\n Thank You");
        return 0; // Exit the function if past return date
    }
    else
    if(yyyy_out>yyyy_return||(yyyy_out==yyyy_return&&mm_out>mm_return)||(yyyy_out==yyyy_return&&mm_out==mm_return&&dd_out>dd_return)) {
         printf("\nInvalid date OR Flights are not available for this date\n");
         printf("\n Thank You");
        return 0;
    }else
    printf(" \nDeparture Flight is at: %02d/%02d/%04d\n", dd_out, mm_out, yyyy_out);
srand(time(0));
hour1 = rand()%24;
minute1 = rand()%60;
hour2 = rand()%24;
minute2 = rand()%60;     
code3= (rand()%(99-10+1))-10;                           
printf("at %d:%d \n ",hour1,minute1);
printf(" \nReturn Flight is at: %02d/%02d/%04d\n", dd_return, mm_return, yyyy_return);                  
    printf("at %d:%d \n ",hour2,minute2); }
     printf("\n\n\tFlight Ticket price is:\tINR ****%d",code3);    
       printf("\n\tEnter Payment Method");
    printf("\n\t1. Internet Banking ");
    printf("\n\t2. Card  ");
    printf("\n\t3. UPI  ");
    to:{
    printf("\n\n\t\tEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:printf("\nEnter the Bank account number: ");
    scanf("%s", num1);
    printf("\nEnter the OTP: ");
    scanf("%s", num2);
    printf("\nPayment Successfull ");
            break;
        case 2:
     printf("\nEnter the Card number: ");
    scanf("%s", num1);
    printf("\nEnter the OTP: ");
    scanf("%s", num2);
    printf("\nPayment Successfull ");
            break;       
            case 3:
         printf("\nEnter the UPI number: ");
    scanf("%d", num1);
    printf("\nEnter the OTP: ");
    scanf("%d", num2);
    printf("\nPayment Successfull ");
            break;        
            default:
            printf("\n\n\tSORRY INVALID CHOICE!");
            printf("\n\n\tPLEASE CHOOSE FROM 1-4");
            printf("\n\n\tDo not forget to choose from 1-4");
            goto to;}
    }    
srand(time(0));
code1 = rand()%100;
code2 = rand()%100;
char randomChar = 'A' + (rand() % 26);
    char randomChar1 = 'A' + (rand() % 6);
    char randomChar2 = 'A' + (rand() % 26);
    char randomChar3 = 'A' + (rand() % 26);
time_t t;   
    time(&t);      
	printf("                                                                             \n");
    printf("_\n");
	printf("\t\tIndian Airlines \t\t\tBoarding Pass \t\n");
	printf("_\n");
	 printf("\t\t\t%s\n", ctime(&t));
	printf("_\n");
	printf("\t\tName of passenger:%s %s\t\t\t\t\t\t\t\t\n",fname,lname);
    printf("\n\tPNR number is: \t%c%d%c%c%d%c%d\n",randomChar1,hour1,randomChar2,randomChar,minute2,randomChar3,hour2);
	printf("\t\tClass:%s\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n",class);
	printf("\t\t Departure Date: %02d/%02d/%04d ", dd_out, mm_out ,yyyy_out);
    printf("at %d:%d \n ",hour1,minute1);
	printf("\t\tFrom %s to %s\t\t\t\t\t\t\t\t\n",origin,destination);
    printf("\t\t\tSeat:%c-%d \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n",randomChar1 ,code1);
    printf("\t\t Return Date: %02d/%02d/%04d ", dd_return, mm_return, yyyy_return);
    printf("at %d:%d \n ",hour2,minute2);
    printf("\t\tFrom %s to %s\t\t\t\t\t\t\t\t\n",destination,origin);
    printf("\t\t\tSeat:%c-%d \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n",randomChar3, code2);
	printf("\t\t\t\t\t \t \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n");
	printf("_\n");
     fprintf(ptr,"                                                                             \n");
    fprintf(ptr,"_\n");
	fprintf(ptr,"\t\tIndian Airlines \t\t\tBoarding Pass \t\n");
	fprintf(ptr,"_\n");
	fprintf(ptr,"\t\t\t%s\n", ctime(&t));
	fprintf(ptr,"_\n");
	fprintf(ptr,"\t\tName of passenger:%s %s\t\t\t\t\t\t\t\t\n",fname,lname);
    fprintf(ptr,"\n\tPNR number is: \t%c%d%c%c%d%c%d\n",randomChar1,hour2,randomChar2,randomChar,minute1,randomChar3,minute2); 
	fprintf(ptr,"\t\tClass:%s\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n",class);
    fprintf(ptr,"\t\t Departure Date: %02d/%02d/%04d ", dd_out, mm_out ,yyyy_out);
     fprintf(ptr,"at %d:%d \n ",hour1,minute1);
	fprintf(ptr,"\t\tFrom %s to %s\t\t\t\t\t\t\t\t\n",origin,destination);
	fprintf(ptr,"\t\t\tSeat:%c-%d \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n",randomChar1, code1);
	fprintf(ptr,"\t\t Return Date: %02d/%02d/%04d ", dd_return, mm_return, yyyy_return);
    fprintf(ptr,"at %d:%d \n ",hour2,minute2);
    fprintf(ptr,"\t\tFrom %s to %s\t\t\t\t\t\t\t\t\n",destination,origin);
    fprintf(ptr,"\t\t\tSeat:%c-%d \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n",randomChar3, code2);
	fprintf(ptr,"\t\t\t\t\t \t \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n");
    fprintf(ptr,"_\n");
	printf("\n\tAre you Want to Book an another Ticket");
	printf("\n\n\t\t 1. Yes");
		printf("\n\n\t\t 2. No");
		printf("\n\n\t\t Enter your choice :");
scanf("%d", &choice); 
		switch (choice)
		{
		case 1:
			break;
		case 2:
		printf("\n THANK YOU  ");
		printf("\n HAPPY JOURNEY");
        return 0;
			default:
			printf("\n\n\t SORRY INVALID CHOICE!");
			printf("\n THANK YOU  ");
		printf("\n HAPPY JOURNEY");
          fclose(ptr);
        return 0;
			}}
            return 0;}

int cancel(){
	int i, choice;
    char ln[50],pnr[9];
        printf("\n\n\t\t\t\t CANCELLATION\t\t\t\t\t");
        printf("\n\tenter the following details\t");
        printf("\n\tEnter PNR/Booking Reference:\t");        
scanf("%s",&pnr);
printf("\n\tenter Last Name:\t");
scanf(" %49s", ln); // Read up to 49 characters until a newline
printf("\n\tCancellation charge per passenger per seat is INR3,500 ");
printf("\n\tAre you conform to cancel ticket:\t");
		printf("\n\n\t\t 1. Yes");
		printf("\n\n\t\t 2. No");
		printf("\n\n\t\t Enter your choice :");
        scanf("%d", &choice);
		switch (choice)
		{
		case 1:
        printf("\nYour request is accepted");
        printf("\n\tCANCEL BOOKING:\t");
		printf("\n 1. credit the amount to the card/bank account");
		printf("\n 2. keep the amount in the credit shell for future booking");
		printf("\n\n\t\t Enter your choice :");
        scanf("%d", &choice); 
		switch (choice){
		case 1:
        printf("\nYour request is accepted");
        printf("\n Amount is credited to the card/bank account within 48hour");
		printf("\n Thank You ");
			break;
		case 2:
        printf("\nYour request is accepted");
        printf("\n Your amount is kept in the credit for future booking");
		printf("\n Thank You ");
		break;
		default:
			printf("\n\n\t SORRY INVALID CHOICE!");
			printf("\n\n\t PLEASE CHOOSE FROM 1-2");
			printf("\n\n\t Do not forget to chose from 1-2");
		}break;
		case 2:
        printf("\nYour request is accepted");
        printf("\n Your Flight is not cancel");
		printf("\n Thank You ");
		break;
		default:
			printf("\n\n\t SORRY INVALID CHOICE!");
			printf("\n\n\t PLEASE CHOOSE FROM 1-2");
			printf("\n\n\t Do not forget to chose from 1-2");}return 0;
    }
    int reschedule() {
    int choice, dd, mm, yyyy,dd1,mm1,yyyy1;
    char ln[50],pnr[9];

    printf("\n\n\t\t\t\t RESCHEDULE FLIGHT\t\t\t\t\t");
    printf("\n\tEnter the following details:\t");
    printf("\n\tEnter PNR/Booking Reference:\t");
        scanf("%s", pnr);
    printf("\n\tEnter Last Name:\t");
    scanf("%s", ln);

    printf("\n\tReschedule charge per passenger per seat is INR 2,800 ");
    printf("\n\tAre you sure you want to reschedule the flight?\t");
    printf("\n\n\t\t 1. Yes");
    printf("\n\n\t\t 2. No");
    printf("\n\n\t\t Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nYour request is accepted");
             // Date input and validation
            printf("\nEnter Previous Flight date (dd/mm/yyyy): ");
            scanf("%d/%d/%d", &dd, &mm, &yyyy);
            
            time_t current_time;
            struct tm *current_date;
            time(&current_time);
            current_date = localtime(&current_time);

            if (yyyy < current_date->tm_year + 1900 ||
                (yyyy == current_date->tm_year + 1900 && mm < current_date->tm_mon + 1) ||
                (yyyy == current_date->tm_year + 1900 && mm == current_date->tm_mon + 1 && dd < current_date->tm_mday)) {
                 printf("\nInvalid date OR Flights are not available for this date\n");
                 printf("\n Thank You");
                return 0; // Exit the function if past date
            }

            if (dd == 31 && (mm == 4 || mm == 6 || mm == 9 || mm == 11)) {
                printf("\nInvalid date OR The Flights are not available for this date\n");
                 printf("\n Thank You");
                return 0; // Exit the function for invalid date
            } else if (mm == 2 && (dd == 29 || dd == 30)) {
                printf("\nInvalid date OR The Flights are not available for this date\n");
                 printf("\n Thank You");
                return 0; // Exit the function for invalid date
            }
            printf("\n Enter date of reschedule(dd/mm/yyyy)");
              scanf("%d/%d/%d", &dd1, &mm1, &yyyy1);

            if (yyyy1 < current_date->tm_year + 1900 ||
                (yyyy1 == current_date->tm_year + 1900 && mm1 < current_date->tm_mon + 1) ||
                (yyyy1 == current_date->tm_year + 1900 && mm1 == current_date->tm_mon + 1 && dd1 < current_date->tm_mday)) {
               printf("\nInvalid date OR Flights are not available for this date\n");
                 printf("\n Thank You");
                return 0; // Exit the function if past date
            }

            if (dd1 == 31 && (mm1 == 4 || mm1 == 6 || mm1 == 9 || mm1 == 11)) {
                printf("\nInvalid date OR The Flights are not available for this date\n");
                printf("\n Thank You");
                return 0; // Exit the function for invalid date
            } else if (mm1 == 2 && (dd1 == 29 || dd1 == 30)) {
                printf("\nInvalid date OR The Flights are not available for this date\n");
                printf("\n Thank You");
                return 0; // Exit the function for invalid date
            }
            printf("\nReschedule Flight is at: %02d/%02d/%04d\n", dd1, mm1, yyyy1);
            

            int hour,minute ;
            srand(time(0));
            hour = rand()%24;
            minute = rand()%60;
            printf("at Time: %d:%d \n",hour,minute);
            printf("\nYour Flight is Reschedule Successfully");
            printf("\n Thank You");
            break; 
        case 2:
            printf("\nYour request is accepted. Your Flight is not rescheduled.");
            printf("\nThank You\n");
            break;

        default:
            printf("\n\n\tSORRY INVALID CHOICE!");
            printf("\n\n\tTHANK YOU");
			return 0;
    }}
void display() {
    FILE* ptr = fopen("reser.txt", "r"); // Open the file for reading
    if (ptr == NULL) {
        printf("Error opening the file for reading.\n");
        return;
    }

    char ch;
    while ((ch = fgetc(ptr)) != EOF) {
        putchar(ch);
    }

    fclose(ptr); // Close the file when done with it
}