 #include <stdio.h>

 int main()//Main method
 {

 char county[ 30 ];//Variable for holding county name
 char voting_station[ 50 ];//Variable for holding the name of the voting station
 char over70remark[30]="Success";//Remark if the percentage turnout is over 70%
 char below70over50remark[30]="More Civic Education";//Remark if the percentage turnout is over 50% but below 70%
 char below50remark[30]="Investigate";//Remark if the percentage turnout is below 50%
 int registered_voters;//Variable for holding the number of registered voters
 int expected_voters;//Variable for holding the number of voters expected to register
 double percent_registered;// (number of voters expected to register/number of registered voters)*100

 FILE *IEBC_Ptr; /* IEBC_Ptr = Data from IEBC II.txt file pointer */

 if ( ( IEBC_Ptr = fopen( "IEBC Downloads/Data from IEBC II.txt", "r" ) ) == NULL )
 printf( "File could not be opened\n" );//File opening is unsuccessful
 else {
 printf( "%-10s%-10s%-10s%-5s%-20s%-10s\n", "County", "Station", "Expected", "Registered", "  % Turnout", "Remarks\n_________________________________________________________________________\n" );
 fscanf( IEBC_Ptr, "%s%s%d%d%lf", county, voting_station, &expected_voters, &registered_voters, &percent_registered );

 while ( !feof( IEBC_Ptr ) ) {//If the end of file character is not encountered

        if(percent_registered>75){

                printf( "%-10s%-13s%-10d%-10d%-10.2f%s\n", county, voting_station, expected_voters, registered_voters, percent_registered, over70remark);
                fscanf( IEBC_Ptr, "%s%s%d%d%lf", county, voting_station, &expected_voters, &registered_voters, &percent_registered );}
        if(percent_registered<=75&&percent_registered>50){

                printf( "%-10s%-13s%-10d%-10d%-10.2f%s\n", county, voting_station, expected_voters, registered_voters, percent_registered, below70over50remark);
                fscanf( IEBC_Ptr, "%s%s%d%d%lf", county, voting_station, &expected_voters, &registered_voters, &percent_registered );}
        if(percent_registered<50){

                printf( "%-10s%-13s%-10d%-10d%-10.2f%5s\n", county, voting_station, expected_voters, registered_voters, percent_registered, below50remark );
                fscanf( IEBC_Ptr, "%s%s%d%d%lf", county, voting_station, &expected_voters, &registered_voters, &percent_registered );}

 }

 fclose( IEBC_Ptr );//Close the file
 }

 return 0;//Indication of successful execution of program
 }
