import java.io.*;
import java.util.*;


public class macroalatable
{
	public static void main(String args[])throws IOException
	{
		int index=1;
		int macroindex=0;
		String mname[]=new String[10];
		String arg[]=new String[10];
		String output =new Scanner(new File("inputforala.txt")).useDelimiter("\\Z").next();
		String result1[]=output.split("[,\\s\\?]");
		for(int k=0;k<result1.length;k++)
	    	{
			if(result1[k].equals("MACRO")||result1[k].equals("macro"))      
			{
				mname[macroindex]=result1[k+1];
				macroindex++;
			}
		}
		System.out.print("\n\nARGUMENT LIST ARRAY\n——————————–");
		for(int k=0;k<result1.length;k++)    
		{
			if(result1[k].equals(mname[0]))      		
			{
				arg[0]=result1[k+1];
				arg[1]=result1[k+2];
			}    		
		}
		System.out.println("\nINDEX\t ARGUMENTS");
		System.out.println("\n"+index+"\t"+arg[0]+"\n"+(index+1)+"\t"+arg[1]+"\n");
	}
}

