package lib.test;

import java.util.Scanner;

import lib.copy.LibCopy;

public class Test {

	static {
		System.loadLibrary("copy");
	}

	public static void main(String[] args) {

		String source, destination = "";

		if (args.length >= 2) {
			source = args[0];
			destination = args[1];
		} else {
			Scanner input = new Scanner(System.in);
			print("Enter source file: ");
			source = input.nextLine();
			print("Enter destination file: ");
			destination = input.nextLine();
		}

		if (source.trim().length() != 0 && destination.trim().length() != 0) {
			print("Source : (" + source.trim() + ")\nDestination : (" + destination.trim() + ")\n");

			String copyResult = new LibCopy().copyF(source.trim(), destination.trim());

			print(copyResult + "\n");
		}

	}

	private static <T> void print(T obj) {
		System.out.print(obj);
	}
}
