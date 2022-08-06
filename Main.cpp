#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//SIZE  OF THE DATASET IS HARDCODED 100
//For Some Reasone It outputs Nan with a learning rate of 0.01

//Struct For most of The varibales
struct Data
{
    //SIZE Of DataSet
    int SIZE;
    //X,Y 
    double x[500];
    double y[500];
    //Two Parametrs
    float m,b;
    //learning rate and Irataions 
    float LearningRate;
    int Iritaion;
    //MSE
    double MSE;
};
struct Data *Read_CSV(char*filename,struct Data *FilesData)
{
    //Creating a File Pointer
    //Opening a stream
    FILE *Data=fopen(filename,"r");
    //Cretaing a array to store every line that we read
    char line[(*FilesData).SIZE];
    //Creating A string pointer
    char *StringPoniter;
    //Reading Line By Line Until There is no Line to Read!!!! 
    for (int i = 0;fgets(line,(*FilesData).SIZE,Data)!=NULL;i++)
    {
    //Using strtok to cut the lines in half 
        //Cutting till first coma which means x value
        StringPoniter=strtok(line,",");
        //Converting it to float and then storing it inside the x array 
        (*FilesData).x[i]=atof(StringPoniter);

        //Cutting till end of the line which means y value
        StringPoniter=strtok(NULL,"");
        //Converting it to float and then storing it inside the y array 
        (*FilesData).y[i]=atof(StringPoniter);
    }
    //Closing The Stream
    fclose(Data);
    //Returing The Data
    return FilesData;
}
struct Data* Model(struct Data* Data)
{
    //Doing The Irataions
    for (int i = 0; i < Data->Iritaion; i++)
    {
        //Declaring  And Initializing The Parameters 
        double p0=0;
        double p1=0;
        //Intializing MSE
        (*Data).MSE=0;

        //Iritating Through The Dataset
        for (int i = 0; i < (*Data).SIZE; i++)
        {
            ////Declaring And Initializing x,y From The Dataset
            double x=(*Data).x[i];
            double y=(*Data).y[i];
        
            //Calculating h(x)
            double hx=((*Data).m*x+(*Data).b);
            //Calculating Gradient descent
            p1=p1+(2*(y-hx)*-x);
            p0=p0+(2*(y-hx)*-1);  
            //Calculating MSE
            (*Data).MSE=(*Data).MSE+((y-hx)*(y-hx));
        }
        ////Continue Calculating Gradient descent
        p1=(p1/(*Data).SIZE);
        p0=(p0/(*Data).SIZE);
        (*Data).m=(*Data).m-((*Data).LearningRate*p1);
        (*Data).b=(*Data).b-((*Data).LearningRate*p0); 
        //Continue Calculating MSE
        (*Data).MSE=((*Data).MSE/(*Data).SIZE)/(*Data).SIZE;
       //Printing P0&P1 For Each Irtaion
        printf("\nm:%f AND b:%f",(*Data).m,(*Data).b); 
        }
    //Returning The Data
    return Data;
}
int main()
{
    printf("\nLinear Regression in C++\n");
    //Getting values back from function
    struct Data mydata; 
    //X Value From User
    float x_user;
    //Allocating Dynamic Memorey
    char CSV_Path[100];
    // Asking For CSV
    printf("\nCSV Path:");
    scanf("%s",CSV_Path);
    //Asking for SIZE 
    printf("Size Of DataSet:");
    scanf("%i",&mydata.SIZE);
    //Asking For P1
    printf("Start Value of P1=");
    scanf("%f",&mydata.m);
    //Asking For P0
    printf("Start Value of P0=");
    scanf("%f",&mydata.b);
    //Asking For LearningRate
    printf("BECAREFUL!!!!\nLearning Rate:");
    scanf("%f",&mydata.LearningRate);
    //Asking For Iritaion
    printf("BECAREFUL!!!!\nNumber Of Iritation:");
    scanf("%i",&mydata.Iritaion);
    //Asking for X 
    printf("Enter a Random X Value To Pridict Y:");
    scanf("%f",&x_user);

    //Reading The CSV
    mydata=*(Read_CSV(CSV_Path,&mydata));

    //Recording Starting Time
    long Before_Training=clock();
    //Training The model
    mydata=(*Model(&mydata));
    //Recording Ending Time
    long Affter_Training=clock();

    //Pridicting The Y 
    float y_Pridict=mydata.m*x_user+mydata.b;
    //Printing The Information
    printf("\nMSE Is:%lf",mydata.MSE);
    printf("\np1:%f \np0:%f",mydata.m,mydata.b);
    printf("\nAccuracy Score Is %lf",(double)100.0-mydata.MSE);
    printf("\nTraining Time Is %lf Seconds",(double)(Affter_Training-Before_Training)/CLOCKS_PER_SEC);
    printf("\nA If X Is %f And The Pridicited Y For The X is %f \n\n",x_user,y_Pridict);
    return 0;   
}
