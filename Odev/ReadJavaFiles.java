/**
*
* @author Sena Erden sena.erden@ogr.sakarya.edu.tr
* @since 01.04.2024
* <p>
* Bu sınıf,githubtan çekilmiş olan dosyaları dosyaları okur .
* </p>
*/
package Odev;

import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;

public class ReadJavaFiles {
	public static String readFileContent(String file) {
		StringBuilder content = new StringBuilder();
		try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
			String line;
			while ((line = reader.readLine()) != null) {
				content.append(line).append("\n");
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		return content.toString();
	}
}
