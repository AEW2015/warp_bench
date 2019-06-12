/* 
 ****************************************************************************
 *
 *                   "DHRYSTONE" Benchmark Program
 *                   -----------------------------
 *
 *  Version:    C, Version 2.1
 *
 *  File:       dhry_1.c (part 2 of 3)
 *
 *  Date:       May 25, 1988
 *
 *  Author:     Reinhold P. Weicker
 *
 ****************************************************************************
 */

#include "dhry.h"
#include "xtime_l.h"
#include "xparameters.h"

/* Global Variables: */

Rec_Pointer     Ptr_Glob,
                Next_Ptr_Glob;
int             Int_Glob;
Boolean         Bool_Glob;
char            Ch_1_Glob,
                Ch_2_Glob;
int             Arr_1_Glob [50];
int             Arr_2_Glob [50] [50];

Enumeration     Func_1 ();
  /* forward declaration necessary since Enumeration may not simply be int */

#ifndef REG
        Boolean Reg = false;
#define REG
        /* REG becomes defined as empty */
        /* i.e. no register variables   */
#else
        Boolean Reg = true;
#endif

/* variables for time measurement: */


#define TICKS_PER_SECOND 				(COUNTS_PER_SECOND)
#define TICKS_PER_MICROSECOND 			(COUNTS_PER_SECOND / (1000000.0))
#define Too_Small_Time 					(2*COUNTS_PER_SECOND)


XTime        	Begin_Time,
                End_Time,
                User_Time;

double           Microseconds,
                Dhrystones_Per_Second;

/* end of variables for time measurement */

#ifdef NO_MALLOC
Rec_Type tmp_var1, tmp_var2;
#endif

main ()
/*****/

  /* main program, corresponds to procedures        */
  /* Main and Proc_0 in the Ada version             */
{
        One_Fifty       Int_1_Loc;
  REG   One_Fifty       Int_2_Loc;
        One_Fifty       Int_3_Loc;
  REG   char            Ch_Index;
        Enumeration     Enum_Loc;
        Str_30          Str_1_Loc;
        Str_30          Str_2_Loc;
  REG   int             Run_Index;
  REG   int             Number_Of_Runs;

  /* Initializations */
  init_platform();

#ifdef NO_MALLOC
  Next_Ptr_Glob = (Rec_Pointer) &tmp_var1;
  Ptr_Glob = (Rec_Pointer) &tmp_var2;
#else
  Next_Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));
  Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));
#endif

  Ptr_Glob->Ptr_Comp                    = Next_Ptr_Glob;
  Ptr_Glob->Discr                       = Ident_1;
  Ptr_Glob->variant.var_1.Enum_Comp     = Ident_3;
  Ptr_Glob->variant.var_1.Int_Comp      = 40;
  strcpy (Ptr_Glob->variant.var_1.Str_Comp,
          "DHRYSTONE PROGRAM, SOME STRING");
  strcpy (Str_1_Loc, "DHRYSTONE PROGRAM, 1'ST STRING");

  Arr_2_Glob [8][7] = 10;
        /* Was missing in published program. Without this statement,    */
        /* Arr_2_Glob [8][7] would have an undefined value.             */
        /* Warning: With 16-Bit processors and Number_Of_Runs > 32000,  */
        /* overflow may occur for this array element.                   */

  printf ("\n");
  printf ("Dhrystone Benchmark, Version 2.1 (Language: C)\n");
  printf ("\n");
  if (Reg)
  {
    printf ("Program compiled with 'register' attribute\n");
    printf ("\n");
  }
  else
  {
    printf ("Program compiled without 'register' attribute\n");
    printf ("\n");
  }
  {
	  printf("Number_Of_Runs set to 15000000");
	  Number_Of_Runs = 15000000;
  }
  printf ("\n");

  printf ("Execution starts, %d runs through Dhrystone\n", Number_Of_Runs);

  /***************/
  /* Start timer */
  /***************/

  XTime_GetTime(&Begin_Time);

  for (Run_Index = 1; Run_Index <= Number_Of_Runs; ++Run_Index)
  {

    Proc_5();
    Proc_4();
      /* Ch_1_Glob == 'A', Ch_2_Glob == 'B', Bool_Glob == true */
    Int_1_Loc = 2;
    Int_2_Loc = 3;
    strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
    Enum_Loc = Ident_2;
    Bool_Glob = ! Func_2 (Str_1_Loc, Str_2_Loc);
      /* Bool_Glob == 1 */
    while (Int_1_Loc < Int_2_Loc)  /* loop body executed once */
    {
      Int_3_Loc = 5 * Int_1_Loc - Int_2_Loc;
        /* Int_3_Loc == 7 */
      Proc_7 (Int_1_Loc, Int_2_Loc, &Int_3_Loc);
        /* Int_3_Loc == 7 */
      Int_1_Loc += 1;
    } /* while */
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    Proc_8 (Arr_1_Glob, Arr_2_Glob, Int_1_Loc, Int_3_Loc);
      /* Int_Glob == 5 */
    Proc_1 (Ptr_Glob);
    for (Ch_Index = 'A'; Ch_Index <= Ch_2_Glob; ++Ch_Index)
                             /* loop body executed twice */
    {
      if (Enum_Loc == Func_1 (Ch_Index, 'C'))
          /* then, not executed */
        {
        Proc_6 (Ident_1, &Enum_Loc);
        strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 3'RD STRING");
        Int_2_Loc = Run_Index;
        Int_Glob = Run_Index;
        }
    }
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    Int_2_Loc = Int_2_Loc * Int_1_Loc;
    Int_1_Loc = Int_2_Loc / Int_3_Loc;
    Int_2_Loc = 7 * (Int_2_Loc - Int_3_Loc) - Int_1_Loc;
      /* Int_1_Loc == 1, Int_2_Loc == 13, Int_3_Loc == 7 */
    Proc_2 (&Int_1_Loc);
      /* Int_1_Loc == 5 */

  } /* loop "for Run_Index" */

  /**************/
  /* Stop timer */
  /**************/


  XTime_GetTime(&End_Time);

  printf ("Execution ends\n");
  printf ("\n");
  printf ("Final values of the variables used in the benchmark:\n");
  printf ("\n");
  printf ("Int_Glob:            %d\n", Int_Glob);
  printf ("        should be:   %d\n", 5);
  printf ("Bool_Glob:           %d\n", Bool_Glob);
  printf ("        should be:   %d\n", 1);
  printf ("Ch_1_Glob:           %c\n", Ch_1_Glob);
  printf ("        should be:   %c\n", 'A');
  printf ("Ch_2_Glob:           %c\n", Ch_2_Glob);
  printf ("        should be:   %c\n", 'B');
  printf ("Arr_1_Glob[8]:       %d\n", Arr_1_Glob[8]);
  printf ("        should be:   %d\n", 7);
  printf ("Arr_2_Glob[8][7]:    %d\n", Arr_2_Glob[8][7]);
  printf ("        should be:   Number_Of_Runs + 10\n");
  printf ("Ptr_Glob->\n");
  printf ("  Ptr_Comp:          %d\n", (int) Ptr_Glob->Ptr_Comp);
  printf ("        should be:   (implementation-dependent)\n");
  printf ("  Discr:             %d\n", Ptr_Glob->Discr);
  printf ("        should be:   %d\n", 0);
  printf ("  Enum_Comp:         %d\n", Ptr_Glob->variant.var_1.Enum_Comp);
  printf ("        should be:   %d\n", 2);
  printf ("  Int_Comp:          %d\n", Ptr_Glob->variant.var_1.Int_Comp);
  printf ("        should be:   %d\n", 17);
  printf ("  Str_Comp:          %s\n", Ptr_Glob->variant.var_1.Str_Comp);
  printf ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  printf ("Next_Ptr_Glob->\n");
  printf ("  Ptr_Comp:          %d\n", (int) Next_Ptr_Glob->Ptr_Comp);
  printf ("        should be:   (implementation-dependent), same as above\n");
  printf ("  Discr:             %d\n", Next_Ptr_Glob->Discr);
  printf ("        should be:   %d\n", 0);
  printf ("  Enum_Comp:         %d\n", Next_Ptr_Glob->variant.var_1.Enum_Comp);
  printf ("        should be:   %d\n", 1);
  printf ("  Int_Comp:          %d\n", Next_Ptr_Glob->variant.var_1.Int_Comp);
  printf ("        should be:   %d\n", 18);
  printf ("  Str_Comp:          %s\n",
                                Next_Ptr_Glob->variant.var_1.Str_Comp);
  printf ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  printf ("Int_1_Loc:           %d\n", Int_1_Loc);
  printf ("        should be:   %d\n", 5);
  printf ("Int_2_Loc:           %d\n", Int_2_Loc);
  printf ("        should be:   %d\n", 13);
  printf ("Int_3_Loc:           %d\n", Int_3_Loc);
  printf ("        should be:   %d\n", 7);
  printf ("Enum_Loc:            %d\n", Enum_Loc);
  printf ("        should be:   %d\n", 1);
  printf ("Str_1_Loc:           %s\n", Str_1_Loc);
  printf ("        should be:   DHRYSTONE PROGRAM, 1'ST STRING\n");
  printf ("Str_2_Loc:           %s\n", Str_2_Loc);
  printf ("        should be:   DHRYSTONE PROGRAM, 2'ND STRING\n");
  printf ("\n");

  


  User_Time = End_Time - Begin_Time;

  if (User_Time < Too_Small_Time)
  {
    printf ("Measured time too small to obtain meaningful results\n");
    printf ("Please increase number of runs\n");
    printf ("User ticks: %ld\nTarget: %ld\n", (long)User_Time, (long)Too_Small_Time);
    printf ("Ratio: %f\n", ((float)User_Time)/((float)Too_Small_Time));
    printf ("\n");
  }
  else
  {
	printf ("User ticks: %lld\nTarget: %lld\n", (long long)User_Time, (long long)Too_Small_Time);
	printf ("Ratio: %f\n", ((float)User_Time)/((float)Too_Small_Time));
	printf ("\n");

    printf("# of ticks = %lld\n", (long long)User_Time);
    printf("begin: %lld, end: %lld\n", (long long)Begin_Time, (long long)End_Time);
    printf("ticks / microsecond: %6.3f\n", (float)TICKS_PER_MICROSECOND);

    Microseconds = (double) User_Time / (double) TICKS_PER_MICROSECOND;

    Dhrystones_Per_Second = ((double) Number_Of_Runs) * TICKS_PER_SECOND/ (double) User_Time;

    printf ("Microseconds for one run through Dhrystone: ");
    printf ("%6.1lf \n", Microseconds);
    printf ("Dhrystones per Second:                      ");
    printf ("%6.1lf \n", Dhrystones_Per_Second);
    printf ("\n");

    /* calculate and print dmips/mhz */
    double dmips = Dhrystones_Per_Second / 1757.0;
    double dmips_per_mhz = dmips / ((long long)XPAR_CPU_CORTEXA53_0_CPU_CLK_FREQ_HZ/1000000.0);

     /* we expect dmips_per_mhz = 0.92 for MicroBlaze, or less if fewer options are enabled
      * since we can't print out float's using xil_printf, print it out as an integer
      * after multiplying by 100
      */

     printf("DMIPS          : %6.1f\n", dmips);
     printf("DMIPS/Mhz      : %6.4f\n", dmips_per_mhz);
     printf("Proc Frequency : %d Hz\n", XPAR_CPU_CORTEXA53_0_CPU_CLK_FREQ_HZ);
  }

  cleanup_platform();
}


Proc_1 (Ptr_Val_Par)
/******************/

REG Rec_Pointer Ptr_Val_Par;
    /* executed once */
{
  REG Rec_Pointer Next_Record = Ptr_Val_Par->Ptr_Comp;
                                        /* == Ptr_Glob_Next */
  /* Local variable, initialized with Ptr_Val_Par->Ptr_Comp,    */
  /* corresponds to "rename" in Ada, "with" in Pascal           */

  structassign (*Ptr_Val_Par->Ptr_Comp, *Ptr_Glob);
  Ptr_Val_Par->variant.var_1.Int_Comp = 5;
  Next_Record->variant.var_1.Int_Comp
        = Ptr_Val_Par->variant.var_1.Int_Comp;
  Next_Record->Ptr_Comp = Ptr_Val_Par->Ptr_Comp;
  Proc_3 (&Next_Record->Ptr_Comp);
    /* Ptr_Val_Par->Ptr_Comp->Ptr_Comp
                        == Ptr_Glob->Ptr_Comp */
  if (Next_Record->Discr == Ident_1)
    /* then, executed */
  {
    Next_Record->variant.var_1.Int_Comp = 6;
    Proc_6 (Ptr_Val_Par->variant.var_1.Enum_Comp,
           &Next_Record->variant.var_1.Enum_Comp);
    Next_Record->Ptr_Comp = Ptr_Glob->Ptr_Comp;
    Proc_7 (Next_Record->variant.var_1.Int_Comp, 10,
           &Next_Record->variant.var_1.Int_Comp);
  }
  else /* not executed */
    structassign (*Ptr_Val_Par, *Ptr_Val_Par->Ptr_Comp);
} /* Proc_1 */


Proc_2 (Int_Par_Ref)
/******************/
    /* executed once */
    /* *Int_Par_Ref == 1, becomes 4 */

One_Fifty   *Int_Par_Ref;
{
  One_Fifty  Int_Loc;
  Enumeration   Enum_Loc;

  Int_Loc = *Int_Par_Ref + 10;
  do /* executed once */
    if (Ch_1_Glob == 'A')
      /* then, executed */
    {
      Int_Loc -= 1;
      *Int_Par_Ref = Int_Loc - Int_Glob;
      Enum_Loc = Ident_1;
    } /* if */
  while (Enum_Loc != Ident_1); /* true */
} /* Proc_2 */


Proc_3 (Ptr_Ref_Par)
/******************/
    /* executed once */
    /* Ptr_Ref_Par becomes Ptr_Glob */

Rec_Pointer *Ptr_Ref_Par;

{
  if (Ptr_Glob != Null)
    /* then, executed */
    *Ptr_Ref_Par = Ptr_Glob->Ptr_Comp;
  Proc_7 (10, Int_Glob, &Ptr_Glob->variant.var_1.Int_Comp);
} /* Proc_3 */


Proc_4 () /* without parameters */
/*******/
    /* executed once */
{
  Boolean Bool_Loc;

  Bool_Loc = Ch_1_Glob == 'A';
  Bool_Glob = Bool_Loc | Bool_Glob;
  Ch_2_Glob = 'B';
} /* Proc_4 */


Proc_5 () /* without parameters */
/*******/
    /* executed once */
{
  Ch_1_Glob = 'A';
  Bool_Glob = false;
} /* Proc_5 */


        /* Procedure for the assignment of structures,          */
        /* if the C compiler doesn't support this feature       */
#ifdef  NOSTRUCTASSIGN
memcpy (d, s, l)
register char   *d;
register char   *s;
register int    l;
{
        while (l--) *d++ = *s++;
}
#endif


