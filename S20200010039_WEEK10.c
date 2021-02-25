#include<stdio.h>
#include<string.h>
#include<math.h>
int count=0,n=5;
struct stud_infor{
    char firstname[20];
    char lastname[20];
    long long int rollno;
    int cgpa;
    int courses[5];
};
struct stud_infor student[50];



void addstudent(){
    long long int num,i;
    printf("enter the roll number of the student to be added:");
    scanf("%lld",&num);
    for(i=0;i<50;i++){
        if(num==student[i].rollno){
            printf("The given rollno is already registered.Please try again.\n");
            break;   
        }
    }
    if(i==50){
    student[count].rollno=num;
    printf("enter First Name of the student: ");
    scanf("%s", student[count].firstname);
    printf("enter Last Name of the student: ");
    scanf("%s", student[count].lastname);
    printf("enter CGPA of the student: ");
    scanf("%d", &student[count].cgpa);
    printf("the available course id's are: 1,2,3,4,5,6,7\n");
    printf("enter course id's of the student: ");
    for(int k=0;k<5;k++)
    scanf("%d",&student[count].courses[k]);
    }
    count=count+1;
}


void findstudentbyrollno(){
    long long int a=0,rollno;
    printf("enter the roll no of student to get details: ");
    scanf("%lld",&rollno);
    for(int i=0;i<count;i++){
        if(rollno==student[i].rollno){
            ++a;
            printf("The first name of the student is: %s\n",student[i].firstname);
            printf("The last name of the student is: %s\n",student[i].lastname);
            printf("The rollno of the student is: %lld\n",student[i].rollno);
            printf("The CGPA name of the student is: %d\n",student[i].cgpa);
            printf("The course id's of the student are: ");
            for(int j=0;j<n;j++)
                printf("%d ",student[i].courses[j]);
                printf("\n");
        }
    }
    if(a==0) printf("This student is not registered yet.\n");
}


void findstudentbyfirstname(){
    char firstname[20];
    int i;
    printf("enter the first name of the student to get details: ");
    scanf("%s",firstname);
    for(i=0;i<50;i++){
        if(strcmp(firstname,student[i].firstname)==0){
            printf("The first name of the student is: %s\n",student[i].firstname);
            printf("The last name of the student is: %s\n",student[i].lastname);
            printf("The rollno of the student is: %lld\n",student[i].rollno);
            printf("The CGPA name of the student is: %d\n",student[i].cgpa);
            printf("The course id's of the student are: ");
            for(int j=0;j<n;j++)
                printf("%d ",student[i].courses[j]);
                printf("\n\n");
                break;
        }
    }
    if(i==50) printf("There is no student with that first name.Please try again.\n\n");
}



void findstudentbycourseid(){
    int id;
    printf("enter the coure id to get the students list: ");
    scanf("%d",&id);
    printf("The students registered for the course with course id %d are: ",id);
    for(int i=0;i<50;i++){
        for(int j=0;j<5;j++){
            if(id==student[i].courses[j]) printf("%s\n",student[i].firstname);
        }
    }
}


void totalstudents(){
    printf("The total no.of students are: %d\n\n",count);
}
void deletestudent(){
  long long int num;
  int i;
    printf("Enter the rollno to delete the details: ");
    scanf("%lld",&num);
    for(i=0;i<50;i++){
        if(num==student[i].rollno){
            printf("The details of the student are deleted.\n\n");
            for(int j=0;j<49;j++) student[j]=student[j+1];
            count--;
        break;
        }
    }
    if(i==50) printf("There is no student with the given roll no.Please try again.\n\n");
}

void update(){
    long long int rollno;
    int choice,i;
    printf("enter the roll no of student to get details: ");
    scanf("%lld",&rollno);
    for(i=0;i<50;i++){
        if(rollno==student[i].rollno) break;
    }
    if(i==50) printf("There is no student with the given roll no.Please try again.\n\n");
    else{
    printf("enter:\n1 to update first name\n2 to update last name\n3 to update rollno\n4 to update CGPA\n5 to update course id's\n");
    scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nThe first name of student is: %s\n",student[i].firstname);
                printf("Enter new first name: ");
                scanf("%s",&student[i].firstname);
                break;
            case 2:
                printf("The last name of student is: %s\n",student[i].lastname);
                printf("Enter new last name: ");
                scanf("%s",&student[i].lastname);
                break;
            case 3:
                printf("The rollno of student is: %lld\n",student[i].rollno);
                printf("Enter new rollno: ");
                scanf("%lld",&student[i].rollno);
                break;
            case 4:
                printf("The CGPA of student is: %d\n",student[i].cgpa);
                printf("Enter new CGPA: ");
                scanf("%d",&student[i].cgpa);
                break;
            case 5:
                printf("enter new course id's: ");
                for(int l=0;l<5;l++) scanf("%d",&student[i].courses[l]);
                break;
        }
    }
}


void studentstatistics(){
    int mean=0,median,s_d;
    for(int i=0;i<count;i++){
        mean+=student[i].cgpa;
    }
    printf("The mean CGPA of all the students is: %d\n",mean);
    int arr[50];
    for(int f=0;f<count;f++) arr[f]=student[f].cgpa;
    void swap(int *p,int *q) {
        int t;
         t=*p; 
        *p=*q; 
        *q=t;
    }

    void sort(int a[],int n) { 
    int i,j,temp;

        for(i = 0;i < n-1;i++) {
            for(j = 0;j < n-i-1;j++) {
                if(a[j] > a[j+1])
                    swap(&a[j],&a[j+1]);
                }
            }
        }

    sort(arr,count);
    median=((count+1)/2)-1;
    printf("The median of CGPA of students is: %d\n",arr[median]);
    float Standard_Deviation(int arr[]) {
    float sum = 0.0, number, SD = 0.0;
    int i;
    for (i = 0; i < 10; ++i) {
        sum += arr[i];
    }
    number = sum / 10;
    for (i = 0; i < 10; ++i)
        SD += pow(arr[i] - number, 2);
    return sqrt(SD / 10);
    }
    printf("The Standard Deviation of CGPA of students is: %f\n\n",Standard_Deviation);
}

void coursesummaries(){
    int tot[7]={0};
    for(int i=0;i<count;i++){
        for(int j=0;j<5;j++){
            switch(student[i].courses[j]){
                case 1:
                    tot[0]++;
                    break;
                case 2:
                    tot[1]++;
                    break;
                case 3:
                    tot[2]++;
                    break;
                case 4:
                    tot[3]++;
                    break;
                case 5:
                    tot[4]++;
                    break;
                case 6:
                    tot[5]++;
                    break;
                case 7:
                    tot[6]++;
                    break;
            }
        }
    }
    for(int d=0;d<7;d++){
        printf("No.of students registered for the course %d are: %d\n\n",d+1,tot[d]);
    }
}


int main(){
    int choice=0;
    do{
        printf("\n\t\tWelcome to iSiMS\nIIITS Student-Information Management System\n");
        printf("\nEnter: \n");
        printf("\t0. to Quit\n");
        printf("\t1. add extra student: \n");
        printf("\t2. find student by roll no: \n");
        printf("\t3. find student by first name: \n");
        printf("\t4. find student by course id's: \n");
        printf("\t5. find total number of students: \n");
        printf("\t6. delete student by roll no: \n");
        printf("\t7. update student by roll no: \n");
        printf("\t8. student statistics: \n");
        printf("\t9. course summaries: \n");
        printf(" Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: addstudent(); break;
            case 2: findstudentbyrollno(); break;
            case 3: findstudentbyfirstname(); break;
            case 4: findstudentbycourseid();break;
            case 5: totalstudents();break;
            case 6: deletestudent();break;
            case 7: update();break;
            case 8: studentstatistics();break;
            case 9: coursesummaries();break;
        }
    }while(choice!=0);
    return 0;
}