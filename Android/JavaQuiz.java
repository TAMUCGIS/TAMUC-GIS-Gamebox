import java.util.*;
import java.io.*;
public class JavaQuizGame 
{

    private static int size;
    public static void main(String[] args) throws FileNotFoundException 
    {
        String question;
        String corAns;
        String wroAns1;
        String wroAns2;
        String wroAns3;
        Questions q;
        
        ArrayList<Questions> allQuestions=new ArrayList<Questions>();
        Scanner in = new Scanner(new File("src\\questions.txt"));
        Scanner user = new Scanner(System.in);
        size=0;
        while(in.hasNext())
        {
           question=in.nextLine();
           corAns=in.nextLine();           
           wroAns1=in.nextLine();
           wroAns2=in.nextLine();
           wroAns3=in.nextLine();
           q=new Questions(question, corAns, wroAns1,wroAns2, wroAns3);
           q.scrambleAns();
           allQuestions.add(q);
           size++;
        }
        in.close();
        //The following is purely for display puroposes and will not continue into final version
        Questions temp;
        String userAns;
        boolean iscorrect;
        int numRight=0;
        int numWrong=0;
        for(int i =0; i<size;i++)
        {
            temp=allQuestions.get(i);
            System.out.println(temp.getQuestion());
            temp.printAns();
            userAns=user.nextLine();
            iscorrect =temp.check(userAns);    
            if(iscorrect)
            {
                numRight++;
                System.out.println("Correct");
            }
            else
            {
                numWrong++;
                System.out.println("Inncorrect");
            }
        }
        System.out.println("You got "+numRight+" correct, and "+ numWrong+" incorrect!");
        user.close();
    }
}
