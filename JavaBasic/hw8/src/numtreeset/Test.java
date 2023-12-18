package numtreeset;

import numarraylist.NumArrayList;
import testutil.TestRunner;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Random;



public class Test {
	public static void main(String[] args) {
		TestRunner.enableException(true);
		TestRunner.runTest(()->{
			int a = 5;
			int b = 5;
			Random rand = new Random();
			HashSet<Integer> uniqueNumbers = new HashSet<>();
			while (uniqueNumbers.size() < a) {
				uniqueNumbers.add(rand.nextInt(100));
			}
			List<Integer> additionalNumbers = new ArrayList<>();
			List<Integer> uniqueList = new ArrayList<>(uniqueNumbers);
			for (int i = 0; i < b; i++) {
				additionalNumbers.add(uniqueList.get(rand.nextInt(uniqueList.size())));
			}
			List<Integer> combinedList = new ArrayList<>(uniqueNumbers);
			combinedList.addAll(additionalNumbers);
			Collections.shuffle(combinedList);
			int[] combinedArray = combinedList.stream().mapToInt(i -> i).toArray();
			NumTreeSet s = new NumTreeSet(combinedArray);
			System.out.println("Input: " + combinedList);
			System.out.println("Output: " + s.work());
			System.out.println("Ans: " + a);
			if (s.work() == a) {
				System.out.println("Accept");
			} else {
				System.out.println("Wrong Answer");
			}
		},1000);
		TestRunner.runTest(()->{
			int a = 10;
			int b = 0;
			Random rand = new Random();
			HashSet<Integer> uniqueNumbers = new HashSet<>();
			while (uniqueNumbers.size() < a) {
				uniqueNumbers.add(rand.nextInt(100));
			}
			List<Integer> additionalNumbers = new ArrayList<>();
			List<Integer> uniqueList = new ArrayList<>(uniqueNumbers);
			for (int i = 0; i < b; i++) {
				additionalNumbers.add(uniqueList.get(rand.nextInt(uniqueList.size())));
			}
			List<Integer> combinedList = new ArrayList<>(uniqueNumbers);
			combinedList.addAll(additionalNumbers);
			Collections.shuffle(combinedList);
			int[] combinedArray = combinedList.stream().mapToInt(i -> i).toArray();
			NumTreeSet s = new NumTreeSet(combinedArray);
			System.out.println("Input: " + combinedList);
			System.out.println("Output: " + s.work());
			System.out.println("Ans: " + a);
			if (s.work() == a) {
				System.out.println("Accept");
			} else {
				System.out.println("Wrong Answer");
			}
		},1000);
		TestRunner.runTest(()->{
			int a = 1;
			int b = 20;
			Random rand = new Random();
			HashSet<Integer> uniqueNumbers = new HashSet<>();
			while (uniqueNumbers.size() < a) {
				uniqueNumbers.add(rand.nextInt(100));
			}
			List<Integer> additionalNumbers = new ArrayList<>();
			List<Integer> uniqueList = new ArrayList<>(uniqueNumbers);
			for (int i = 0; i < b; i++) {
				additionalNumbers.add(uniqueList.get(rand.nextInt(uniqueList.size())));
			}
			List<Integer> combinedList = new ArrayList<>(uniqueNumbers);
			combinedList.addAll(additionalNumbers);
			Collections.shuffle(combinedList);
			int[] combinedArray = combinedList.stream().mapToInt(i -> i).toArray();
			NumTreeSet s = new NumTreeSet(combinedArray);
			System.out.println("Input: " + combinedList);
			System.out.println("Output: " + s.work());
			System.out.println("Ans: " + a);
			if (s.work() == a) {
				System.out.println("Accept");
			} else {
				System.out.println("Wrong Answer");
			}
		},1000);
		TestRunner.runTest(()->{
			int a = 30;
			int b = 20;
			Random rand = new Random();
			HashSet<Integer> uniqueNumbers = new HashSet<>();
			while (uniqueNumbers.size() < a) {
				uniqueNumbers.add(rand.nextInt(100));
			}
			List<Integer> additionalNumbers = new ArrayList<>();
			List<Integer> uniqueList = new ArrayList<>(uniqueNumbers);
			for (int i = 0; i < b; i++) {
				additionalNumbers.add(uniqueList.get(rand.nextInt(uniqueList.size())));
			}
			List<Integer> combinedList = new ArrayList<>(uniqueNumbers);
			combinedList.addAll(additionalNumbers);
			Collections.shuffle(combinedList);
			int[] combinedArray = combinedList.stream().mapToInt(i -> i).toArray();
			NumTreeSet s = new NumTreeSet(combinedArray);
//			System.out.println("Input: " + combinedList);
			System.out.println("Output: " + s.work());
			System.out.println("Ans: " + a);
			if (s.work() == a) {
				System.out.println("Accept");
			} else {
				System.out.println("Wrong Answer");
			}
		},1000);
		TestRunner.runTest(()->{
			int a = 70;
			int b = 30;
			Random rand = new Random();
			HashSet<Integer> uniqueNumbers = new HashSet<>();
			while (uniqueNumbers.size() < a) {
				uniqueNumbers.add(rand.nextInt(100));
			}
			List<Integer> additionalNumbers = new ArrayList<>();
			List<Integer> uniqueList = new ArrayList<>(uniqueNumbers);
			for (int i = 0; i < b; i++) {
				additionalNumbers.add(uniqueList.get(rand.nextInt(uniqueList.size())));
			}
			List<Integer> combinedList = new ArrayList<>(uniqueNumbers);
			combinedList.addAll(additionalNumbers);
			Collections.shuffle(combinedList);
			int[] combinedArray = combinedList.stream().mapToInt(i -> i).toArray();
			NumTreeSet s = new NumTreeSet(combinedArray);
//			System.out.println("Input: " + combinedList);
			System.out.println("Output: " + s.work());
			System.out.println("Ans: " + a);
			if (s.work() == a) {
				System.out.println("Accept");
			} else {
				System.out.println("Wrong Answer");
			}
		},1000);

	}
}
