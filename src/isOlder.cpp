/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#include<stdio.h>
int validatedate(int year,int mon,int day);
int isOlder(char *dob1, char *dob2)
{
        int year1,year2,mon1,mon2,day1,day2,valid1,valid2,count1=0,count2=0,i;
        for (i = 0; dob1[i]!='\0'; i++)
            {

            ++count1;
            }
            for (i = 0; dob2[i] != '\0'; i++)
            ++count2;
        if(count1==10&&count2==10)
        {



        day1=(dob1[0]-'0')*10+dob1[1]-'0';
        day2=(dob2[0]-'0')*10+dob2[1]-'0';
        mon1=(dob1[3]-'0')*10+dob1[4]-'0';
        mon2=(dob2[3]-'0')*10+dob2[4]-'0';
        year1=(dob1[6]-'0')*1000+(dob1[7]-'0')*100+(dob1[8]-'0')*10+dob1[9]-'0';
        year2=(dob2[6]-'0')*1000+(dob2[7]-'0')*100+(dob2[8]-'0')*10+dob2[9]-'0';
        valid1=validatedate(year1,mon1,day1);
        valid2=validatedate(year2,mon2,day2);//printf("\n%d %d %d",day1,mon1,year1);printf("\n%d %d %d",day2,mon2,year2); printf("\n%d%d",valid1,valid2);
       if(valid1==0&&valid2==0)
       {
           if(year2>year1)
           {
               return 1;
           }
           else if(year1>year2)
           {
               return 2;
           }
           else
            {
                if(mon2>mon1)
                {
                    return 1;
                }
                else if(mon1>mon2)
                {
                    return 2;
                }
                else
                    {
                        if(day2>day1)
                        {
                            return 1;
                        }
                        else if(day1>day2)
                        {
                            return 2;
                        }
                        else
                        {
                            return 0;
                        }
                    }
            }
       }
       else
       {
           return -1;
       }
        }
        else
            {
                return -1;
            }
}
int validatedate(int year,int mon,int day)
    {
            int date_ok=0;
            if(year%4==0||((year%400==0)&&(year%100!=0)))
            {  // printf("leap year");
                   if(mon<=7)
                    {
                        if(mon%2==1)
                        {
                            if(day>31)
                                date_ok=-1;
                        }
                        else
                        {
                            if(mon==2&&day>29)
                            {
                                 date_ok=-1;
                            }
                            else if(day>30)
                                date_ok=-1;
                        }
                    }
                    else if(mon<=12&&mon>7)
                    {
                        if(mon%2==0)
                        {
                            if(day>31)
                                {
                                    date_ok=-1;
                                }
                        }
                        else if(mon%2==1)
                        {
                            if(day>30)

                                date_ok=-1;
                        }

                    }
                    else if(mon>12)
                        {
                            date_ok=-1;
                        }
                }

            else
                {
                    if(mon<=7)
                    {
                        if(mon%2==1)
                        {
                            if(day>31)
                                date_ok=-1;
                        }
                        else
                        {
                            if(mon==2&&day>28)
                            {
                                 date_ok=-1;
                            }
                            else if(day>30)
                                date_ok=-1;
                        }
                    }
                    else if(mon<=12&&mon>7)
                    {
                        if(mon%2==0)
                        {
                            if(day>31)
                                date_ok=-1;
                        }
                        else if(mon%2==1)
                        {
                            if(day>30)
                                date_ok=-1;
                        }
                    }
                    else
                        {
                            date_ok=-1;
                        }
                }
                return date_ok;
    }


