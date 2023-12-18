package numarraylist;

import testutil.TestRunner;
import java.util.ArrayList;
import java.util.Random;


public class Test {
	
	public static void main(String args[]) {
		TestRunner.enableException(true);
		TestRunner.runTest(()->{
			int a = 5; // 第一个列表的长度
			int b = 5; // 第二个列表的长度
			ArrayList<Integer> list1 = generateRandomList(a, 0, 5000);
			ArrayList<Integer> list2 = generateRandomList(b, 5000, 10000);
			ArrayList<Integer> combinedList = combineLists(list1, list2);
			System.out.println("Input List: " + combinedList);
			int[] array = combinedList.stream().mapToInt(i -> i).toArray();
			NumArrayList l = new NumArrayList(array);
			ArrayList<Integer> res = l.work();
			System.out.println("Output List: " + res);
			System.out.println("Ans: " + list2);
			if (res.equals(list2)) {
				System.out.println("Accept");
			} else {
				System.out.println("Wrong Answer");
			}
		},1000);
		TestRunner.runTest(()->{
			int a = 0; // 第一个列表的长度
			int b = 10; // 第二个列表的长度
			ArrayList<Integer> list1 = generateRandomList(a, 0, 5000);
			ArrayList<Integer> list2 = generateRandomList(b, 5000, 10000);
			ArrayList<Integer> combinedList = combineLists(list1, list2);
			System.out.println("Input List: " + combinedList);
			int[] array = combinedList.stream().mapToInt(i -> i).toArray();
			NumArrayList l = new NumArrayList(array);
			ArrayList<Integer> res = l.work();
			System.out.println("Output List: " + res);
			System.out.println("Ans: " + list2);
			if (res.equals(list2)) {
				System.out.println("Accept");
			} else {
				System.out.println("Wrong Answer");
			}
		},1000);
		TestRunner.runTest(()->{
			int a = 20; // 第一个列表的长度
			int b = 0; // 第二个列表的长度
			ArrayList<Integer> list1 = generateRandomList(a, 0, 5000);
			ArrayList<Integer> list2 = generateRandomList(b, 5000, 10000);
			ArrayList<Integer> combinedList = combineLists(list1, list2);
			System.out.println("Input List: " + combinedList);
			int[] array = combinedList.stream().mapToInt(i -> i).toArray();
			NumArrayList l = new NumArrayList(array);
			ArrayList<Integer> res = l.work();
			System.out.println("Output List: " + res);
			System.out.println("Ans: " + list2);
			if (res.equals(list2)) {
				System.out.println("Accept");
			} else {
				System.out.println("Wrong Answer");
			}
		},1000);
		TestRunner.runTest(()->{
			int a = 50; // 第一个列表的长度
			int b = 50; // 第二个列表的长度
			ArrayList<Integer> list1 = generateRandomList(a, 0, 5000);
			ArrayList<Integer> list2 = generateRandomList(b, 5000, 10000);
			ArrayList<Integer> combinedList = combineLists(list1, list2);
//			System.out.println("Input List: " + combinedList);
			int[] array = combinedList.stream().mapToInt(i -> i).toArray();
			NumArrayList l = new NumArrayList(array);
			ArrayList<Integer> res = l.work();
//			System.out.println("Output List: " + res);
//			System.out.println("Ans: " + list2);
			if (res.equals(list2)) {
				System.out.println("Accept");
			} else {
				System.out.println("Wrong Answer");
			}
		},1000);
		TestRunner.runTest(()->{
			int a = 100; // 第一个列表的长度
			int b = 100; // 第二个列表的长度
			ArrayList<Integer> list1 = generateRandomList(a, 0, 5000);
			ArrayList<Integer> list2 = generateRandomList(b, 5000, 10000);
			ArrayList<Integer> combinedList = combineLists(list1, list2);
//			System.out.println("Input List: " + combinedList);
			int[] array = combinedList.stream().mapToInt(i -> i).toArray();
			NumArrayList l = new NumArrayList(array);
			ArrayList<Integer> res = l.work();
//			System.out.println("Output List: " + res);
//			System.out.println("Ans: " + list2);
			if (res.equals(list2)) {
				System.out.println("Accept");
			} else {
				System.out.println("Wrong Answer");
			}
		},1000);

	}


	private static ArrayList<Integer> generateRandomList(int size, int min, int max) {
		ArrayList<Integer> list = new ArrayList<>();
		Random random = new Random();
		for (int i = 0; i < size; i++) {
			list.add(random.nextInt(max - min) + min);
		}
		return list;
	}


	private static ArrayList<Integer> combineLists(ArrayList<Integer> list1, ArrayList<Integer> list2) {
		ArrayList<Integer> combinedList = new ArrayList<>();
		int index1 = 0, index2 = 0;

		Random random = new Random();
		while (index1 < list1.size() || index2 < list2.size()) {
			if (index1 < list1.size() && (index2 >= list2.size() || random.nextBoolean())) {
				combinedList.add(list1.get(index1++));
			} else if (index2 < list2.size()) {
				combinedList.add(list2.get(index2++));
			}
		}

		return combinedList;
	}
}
