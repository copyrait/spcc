import java.io.*;
import java.util.*;

public class macrodeftable 
{
	public static void main(String args[])throws IOException
	{
		int MDTC=1;
		String output =new Scanner(new File("inputformdt.txt")).useDelimiter("\\Z").next();
		String result[]=output.split("\n");
		System.out.println("\n\nMACRO DEF TABLE\n—————————————–");
		System.out.println("INDEX\tCARD");
		for(int i=1;i<result.length;i++)    
		{
			System.out.println(MDTC+"\t"+result[i]);
			MDTC=MDTC+1;
			if(result[i].equals("MEND"))
				break;
		}
	}
}

