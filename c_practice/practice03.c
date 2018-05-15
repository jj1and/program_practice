#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

main() {
  int studentGrades[STUDENTS][EXAMS]={{93, 68, 80, 92}, {85, 77, 98, 55}, {83, 88, 87, 90}};
  int max=0;
  int min=100;
  int i,k;
  double sbj[EXAMS]={0};
  for (i = 0; i < STUDENTS; i++) {
      printf("\nSTUDENT ID %d :", i+1 );

    for (k = 0; k <EXAMS; k++) {
      printf("%3d", studentGrades[i][k]);

      sbj[k]+= studentGrades[i][k];
      if (max-studentGrades[i][k]<=0) {
        max = studentGrades[i][k];
      }
      if (studentGrades[i][k]-min<=0) {
        min = studentGrades[i][k];
      }

    }
  }
  printf("\n");
  printf("\nmaximum score: %d",max );
  printf("\nminimum score: %d\n",min );
  for ( k = 0; k < EXAMS; k++) {
    printf("\nSubject %d: %3.1f", k+1, sbj[k]/STUDENTS);
  }
  printf("\n");
  return 0;
}
