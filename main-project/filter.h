#ifndef FILTER_H
#define FILTER_H

#include "lecture_subscription.h"

lecture_subscription** filter(lecture_subscription* array[], int size, bool (*check)(lecture_subscription* element), int& result_size);

/*
  <function_name>:
              ,
          true,
    ,

:
    array       -
    size        -
    check       -    .

                   ,
    result_data - ,    - ,



          ,
     (     true)
*/


bool check_lecture_subscription_by_author(lecture_subscription* element);

/*
  check_book_subscription_by_author:
      - ,

:
    element -   ,


    true,           ,  false
*/


bool check_lecture_subscription_by_period(lecture_subscription* element);

/*
  check_book_subscription_by_date:
      - ,           2021-

:
    element -   ,


    true,           2021- ,  false
*/

#endif

