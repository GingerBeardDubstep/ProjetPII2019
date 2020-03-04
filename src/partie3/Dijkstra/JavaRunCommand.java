import java.io.*;

public class JavaRunCommand {

    public static void main(String args[]) {

        String s = null;

        try {

            Process p = Runtime.getRuntime().exec("gcc -Wall nuknuk.c -o nuknuk");
            Process p1 = Runtime.getRuntime().exec("./nuknuk");

            //p.waitFor();
            //Process p = Runtime.getRuntime().exec("./nuknuk");
            
            // BufferedReader stdInput = new BufferedReader(new 
            //      InputStreamReader(p.getInputStream()));

            // BufferedReader stdError = new BufferedReader(new 
            //      InputStreamReader(p.getErrorStream()));

            // // read the output from the command
            // System.out.println("Here is the standard output of the command:\n");
            // while ((s = stdInput.readLine()) != null) {
            //     System.out.println(s);
            // }
            
            // //read any errors from the attempted command
            // System.out.println("Here is the standard error of the command (if any):\n");
            // while ((s = stdError.readLine()) != null) {
            //     System.out.println(s);
            // }
            
            // System.out.println("NukNuk");

            // Process p1 = Runtime.getRuntime().exec("make clean");
            // Process p2 = Runtime.getRuntime().exec("gcc -Wall nukunk.c -o nuknuk");

            System.exit(0);
        }
        catch (IOException e) {
            System.out.println("exception happened - here's what I know: ");
            e.printStackTrace();
            System.exit(-1);
        }

        // try {

        //     Process p1 = Runtime.getRuntime().exec("gcc -Wall nuknuk.c -o nuknuk");

        //     System.exit(0);
        // }
        // catch (IOException e) {
        //     System.out.println("exception happened - here's what I know: ");
        //     e.printStackTrace();
        //     System.exit(-1);
        // }

    }
}
