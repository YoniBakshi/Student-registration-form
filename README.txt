============================================================================
Description : 
This program is a console form (terminal) to sign-in by a student for a study year.
Student need to fill personal information about himself/herself.
There are 6 fields to fill one by one :
1. Name : 
   Cannot contain digits.
2. ID Number :
    Verified by check digit.
3. Year of birth :
    Minimum age to sign-in is 16 and we'll assume maximum age is 100.  
4. Faculty :
   User needs to enter a digit according to it's faculty's symbolize - 1 - Computer Science
							2 - Medicine
							3 - Literatue
5. Year of study :
    There is only one formal track of study years which is constant for each faculty - Computer Science - 4 years.
								       - Medicine              - 7 years.
								       - Literature              - 3 years.
    (The general range for the first check of this field will be between 1 to 7 included).
											
6. Number of courses :
   Amount of courses which the student is planning this year.
   1st & 2nd years - available to take between 2-6 courses.
   3rd & 4th years - available to take between 2-10 courses.
   5th - available to take between 2-8 courses.
    (The general first check of this field is to be minimum 2).
  

Each field will be checked if valid - according to the specific necessary request.
After form is filled, program will make second validation checks for specific details by cross-check  :
1. Cross-details of year of study in relation to the specific entered faculty :
    If faculty is Computer Science - available study of years is between 1 to 4 ONLY. 
    If faculty is Medicine              - available study of years is between 1 to 7 ONLY.
    If faculty is Literature              - available study of years is between 1 to 3 ONLY.
  
2. Cross details of courses in relation to the specific entered faculty :
   1st & 2nd years - available to take between 2-6 courses ONLY.
   3rd & 4th years - available to take between 2-10 courses ONLY.
   5th - available to take between 2-8 courses ONLY.

After filling the form, program will print the form with the filled details :
If there is an error - in addition, a message will be printed on this specific field.
Each validator contain it's own error message - for specific fields and for the cross-detailed checks.
and user will be requested to fill again those specific invalid fields again.
If the whole form is valid - "Thank You" message will be printed and program will finish.


==============================================================================  

Files list :
Header Files :
BaseField.h		-> מחלקה אבסטרקטית המכילה את הפונקציות הנדרשות למילוי השדות בטופס
BaseValidator.h 		-> מחלקת אב המכילה את הפונקציות הנדרשות להודעת שגיאה (המשותפת לכל ה-validators)  
Courses2YearValidator.h	-> מחלקה תבניתית היורשת מ-FormValidator 
			     מחלקה תבניתית האחראית לבצע בדיקת תקינות של כמות הקורסים שהוזנה ביחס לחוג שהוזן
Faculty2YearValidator.h	-> מחלקה תבניתית היורשת מ-FormValidator 
			     מחלקה תבניתית האחראית לבצע בדיקת תקינות של כמות השנים שהוזנה ביחס לחוג שהוזן
FacultyValue.h		-> מחלקה האחראית על השדה : חוג/פאקולטה , ערכם ממוספרים כפי שמפורט לעיל
Field.h			-> מחלקה תבניתית היורשת מ-BaseField 
FieldValidator.h		-> מחלקה תבניתית אבסטרקטית היורשת מ-BaseValidator האחראית על הפונקציה הוירטואלית לבדיקת תקינות עבור כל שדה  
Form.h			-> מחלקה זו אחראית על ניהול הטופס, סדר הפעולות הנדרש
FormValidator.h		-> מחלקה תבניתית אבסטרקטית היורשת מ-BaseValidator האחראית על בדיקת התקינות השנייה ביחס לפאקולטה שהוזנה
IdValidator.h		-> מחלקה תבניתית יורשת מ-FieldValidator מכילה את האלגוריתם לבדיקת ת.ז. - מאומתת לפי ספרת ביקורת
MinValidator.h		-> מחלקה תבניתית יורשת מ-FieldValidator אחראית על בדיקת מינימום הנדרש
NoDigitValidator.h		-> מחלקה תבניתית יורשת מ-FieldValidator אחראית על בדיקת קלט כדי שלא יכיל ספרות (עבור הזנת שדה "שם")
RangeValidator.h		-> מחלקה תבניתית יורשת מ-FieldValidator בודקת האם הקלט נמצא בין 2 ערכים מסויימים שנקבעו


.cpp Files :
main.cpp             		
BaseField.cpp 		-> מחלקה אבסטרקטית המכילה את הפונקציות הנדרשות למילוי השדות בטופס
BaseValidator.cpp		->מחלקת אב המכילה את הפונקציות הנדרשות להודעת שגיאה (המשותפת לכל ה-validators)  
Courses2YearValidator.cpp	-> מחלקה תבניתית היורשת מ-FormValidator 
			     מחלקה תבניתית האחראית לבצע בדיקת תקינות של כמות הקורסים שהוזנה ביחס לחוג שהוזן
Faculty2YearValidator.cpp	-> מחלקה תבניתית היורשת מ-FormValidator 
			     מחלקה תבניתית האחראית לבצע בדיקת תקינות של כמות השנים שהוזנה ביחס לחוג שהוזן
FacultyValue.cpp		-> מחלקה האחראית על השדה : חוג/פאקולטה , ערכם ממוספרים כפי שמפורט לעיל
Field.cpp			-> מחלקה תבניתית היורשת מ-BaseField 
FieldValidator.cpp		-> מחלקה תבניתית אבסטרקטית היורשת מ-BaseValidator האחראית על הפונקציה הוירטואלית לבדיקת תקינות עבור כל שדה
Form.cpp			-> מחלקה זו אחראית על ניהול הטופס, סדר הפעולות הנדרש
FormValidator.cpp		-> מחלקה תבניתית אבסטרקטית היורשת מ-BaseValidator האחראית על הפונקציה הוירטואלית לבדיקת תקינות עבור כל שדה  
IdValidator.cpp		->  מחלקה תבניתית יורשת מ-FieldValidator מכילה את האלגוריתם לבדיקת ת.ז. - מאומתת לפי ספרת ביקורת
MinValidator.cpp		->  מחלקה תבניתית יורשת מ-FieldValidator אחראית על בדיקת מינימום הנדרש
NoDigitValidator.cpp	-> מחלקה תבניתית יורשת מ-FieldValidator אחראית על בדיקת קלט כדי שלא יכיל ספרות (עבור הזנת שדה "שם")
RangeValidator.cpp	-> מחלקה תבניתית יורשת מ-FieldValidator בודקת האם הקלט נמצא בין 2 ערכים מסויימים שנקבעו

============================================================================
Full-Names : Yehonatan Bakshi & Hila Saadon
