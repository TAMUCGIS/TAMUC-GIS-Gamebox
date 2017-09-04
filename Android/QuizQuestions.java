import java.util.*;
public class Questions 
{
    private String quest;
    private String [][]correct;
    private String[][] wrong1;
    private String [][]wrong2;
    private String[][] wrong3;
    private String cloc;
    public Questions(String q, String c, String w1, String w2, String w3)
    {
        quest=q;
        cloc="A";
        correct= new String [1][2];
        wrong1=new String [1][2];
        wrong2=new String [1][2];
        wrong3=new String [1][2];
        correct[0][0]=cloc;
        correct[0][1]=c;
        wrong1[0][0]="B";
        wrong1[0][1]=w1;
        wrong2[0][0]="C";
        wrong2[0][1]=w2;
        wrong3[0][0]="D";
        wrong3[0][1]=w3;
        
    }    
    void scrambleAns()
    {
        Random rand=new Random();
        int ran=rand.nextInt(4)+1;
        String temp;
        
        if(ran==1)
        {
            cloc="A";
        }
        else if(ran==2)
        {
            temp=cloc;
            cloc="B";
            wrong1[0][0]=temp;
        }
        else if (ran ==3)
        {
                temp=cloc;
            cloc="C";
            wrong2[0][0]=temp;
        }
        else if(ran==4)
        {
            temp=cloc;
            cloc="D";
            wrong3[0][0]=temp;
        }
        else
            scrambleAns();
    }
    String getCorrectLoc()
    {
        return cloc;
    }
    String getQuestion()
    {
        return quest;
    }
    String getLoc(String q[][])
    {
        return q[0][0];
    }
    boolean check(String ans)
    {
        if(ans.equalsIgnoreCase(cloc))
            return true;
        else
            return false;
    }          
    void printAns()
    {
        if(cloc=="A")
        {
            System.out.println(cloc + ") " + correct[0][1]);
            System.out.println(wrong1[0][0]+") "+wrong1[0][1]);
            System.out.println(wrong2[0][0]+") "+wrong2[0][1]);
            System.out.println(wrong3[0][0]+") "+wrong3[0][1]);
        }
        else if(cloc=="B")
        {
            System.out.println(wrong1[0][0]+") "+wrong1[0][1]);
            System.out.println(cloc + ") " + correct[0][1]);
            System.out.println(wrong2[0][0]+") "+wrong2[0][1]);
            System.out.println(wrong3[0][0]+") "+wrong3[0][1]);
        }
        else if(cloc=="C")
        {
            System.out.println(wrong2[0][0]+") "+wrong2[0][1]);
            System.out.println(wrong1[0][0]+") "+wrong1[0][1]);
            System.out.println(cloc + ") " + correct[0][1]);
            System.out.println(wrong3[0][0]+") "+wrong3[0][1]);
        }
        else
        {
            System.out.println(wrong3[0][0]+") "+wrong3[0][1]);
            System.out.println(wrong1[0][0]+") "+wrong1[0][1]);
            System.out.println(wrong2[0][0]+") "+wrong2[0][1]);
            System.out.println(cloc + ") " + correct[0][1]);
        }
    
    }
}
