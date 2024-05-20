/**
* @author Sena Erden sena.erden@ogr.sakarya.edu.tr
* @since 01.04.2024
* <p>
* Bu sınıf,github url'sini ister ve klonlar. Bu klonlanan dosyaları repo adlı dosyaya kaydeder.
* </p>
*/
package Odev;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);   
		
		System.out.println("Please enter the GitHub repository URL: ");  //github url iste
		String githubRepoUrl = input.nextLine();
		
		String current = System.getProperty("user.dir");  //kendi bilgisayarına kaydet
		File directory = new File(current + File.separator + "repo"); //repo adlı dosyaya kaydey.
		String  getFile= "git clone " + githubRepoUrl + " " + directory.getAbsolutePath(); 
		
		try {
			Process process = Runtime.getRuntime().exec(getFile);
			int value = process.waitFor();
			
			if (value == 0)  //başarılı şekilde klonlandıysa eğer buraya girer.
			{ 
				System.out.println("Cloning GitHub repository successful.");
				WriteJavaFilesNames.writeJavaFilesNames(directory);
			} 
			else  //daha önce klonlandıysa bu bilgiyi verir. Bilerek bırakılmıştır. 
			{ 
				BufferedReader reader = new BufferedReader(new InputStreamReader(process.getErrorStream()));
				String line;
				boolean error = false;
				while ((line = reader.readLine()) != null) {
					System.out.println(line);
					error = true;
					WriteJavaFilesNames.writeJavaFilesNames(directory);
				}
				if (!error) {
					System.out.println("Failed to clone GitHub repository.");
				}
			}
		} 
		catch (IOException | InterruptedException e) 
		{
			e.printStackTrace();
		}
		input.close();
	}
}
