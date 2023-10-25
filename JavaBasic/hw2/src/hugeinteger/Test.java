package hugeinteger;

import testutil.TestRunner;

import java.util.Arrays;

public class Test {
	public static void main(String[] args) {



		TestRunner.enableException(true);

		TestRunner.runTest(()->{
			HugeInteger a1 = new HugeInteger("12345");
			HugeInteger a2 = new HugeInteger(23333);
			String[] h = new String[]{a1.toString(), a2.toString()};
			String[] ans = {"12345", "23333",};
			System.out.println("Ans: "+ Arrays.toString(h));
			System.out.println("Expected: "+Arrays.toString(ans));
			if (Arrays.equals(h, ans)) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			HugeInteger a1 = new HugeInteger(98);
			a1.add(new HugeInteger(56));
			HugeInteger a2 = new HugeInteger(30);
			a2.add(new HugeInteger(92));
			HugeInteger a3 = new HugeInteger(86);
			a3.add(new HugeInteger(12));
			HugeInteger a4 = new HugeInteger(56);
			a4.add(new HugeInteger(98));
			HugeInteger a5 = new HugeInteger(92);
			a5.add(new HugeInteger(30));
			HugeInteger a6 = new HugeInteger(12);
			a6.add(new HugeInteger(86));
			String[] h = new String[]{a1.toString(), a2.toString(), a3.toString(),
									a4.toString(), a5.toString(), a6.toString()};
			String[] ans = {"154", "122", "98", "154", "122", "98"};
			System.out.println("Ans: "+ Arrays.toString(h));
			System.out.println("Expected: "+Arrays.toString(ans));
			if (Arrays.equals(h, ans)) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			HugeInteger a1 = new HugeInteger("99999999999999999999999999999999");
			a1.add(new HugeInteger(1));
			HugeInteger a2 = new HugeInteger(1);
			a2.add(new HugeInteger("99999999999999999999999999999999"));
			HugeInteger a3 = new HugeInteger("128672");
			a3.add(new HugeInteger("1123999999999999999871328"));
			HugeInteger a4 = new HugeInteger("1123999999999999999871328");
			a4.add(new HugeInteger("128672"));
			String[] h = new String[]{a1.toString(), a2.toString(), a3.toString(),
					a4.toString()};
			String[] ans = {"100000000000000000000000000000000", "100000000000000000000000000000000",
					"1124000000000000000000000", "1124000000000000000000000"};
			System.out.println("Ans: "+ Arrays.toString(h));
			System.out.println("Expected: "+Arrays.toString(ans));
			if (Arrays.equals(h, ans)) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			HugeInteger a1 = new HugeInteger("224116888125126562774899607023");
			a1.add(new HugeInteger("4369037784"));
			HugeInteger a2 = new HugeInteger("4185564591");
			a2.add(new HugeInteger("50071998695835129948519074206"));
			HugeInteger a3 = new HugeInteger("926587390780961560667582853307");
			a3.add(new HugeInteger("8944789589"));
			HugeInteger a4 = new HugeInteger("5226550269");
			a4.add(new HugeInteger("608871729317287953136803468401"));
			HugeInteger a5 = new HugeInteger("441591031438227324407193010730");
			a5.add(new HugeInteger("8570980299"));
			String[] h = new String[]{a1.toString(), a2.toString(), a3.toString(),
					a4.toString(), a5.toString()};
			String[] ans = {"224116888125126562779268644807", "50071998695835129952704638797",
					"926587390780961560676527642896", "608871729317287953142030018670",
					"441591031438227324415763991029"};
			System.out.println("Ans: "+ Arrays.toString(h));
			System.out.println("Expected: "+Arrays.toString(ans));
			if (Arrays.equals(h, ans)) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			HugeInteger a1 = new HugeInteger("710204270463085409520769642893406808763452741442344346269950801706154232635207656351261930");
			a1.add(new HugeInteger("409985297743769925235003326492915657741135029950937434209230478672495151839628984460059128"));
			HugeInteger a2 = new HugeInteger("128261837121017280419885578125602719545293752517001330612942274873291052804456547832833920");
			a2.add(new HugeInteger("772960537811206044707341690656661351928117954504902999155328078572260373691743347407195233"));
			HugeInteger a3 = new HugeInteger("237224252897800727811892109304812053992345075402621833966453602370254953208414540476399823");
			a3.add(new HugeInteger("505856640257870107378565514837847987249664444387012561642617115555576245769295240363712043"));
			HugeInteger a4 = new HugeInteger("545990806829498482207370159409822189681060071438920690923120977923114020068368459917103280");
			a4.add(new HugeInteger("323435417423873444406617698682302267076015361019395383320038366042023551456872839329606699"));
			HugeInteger a5 = new HugeInteger("719468364279371705803333222618465152444651213232615904206038857390474396648442510615090293");
			a5.add(new HugeInteger("601418711133748156089639881488066266317464382361974430734206452090950082270864617261839054"));
			String[] h = new String[]{a1.toString(), a2.toString(), a3.toString(),
					a4.toString(), a5.toString()};
			String[] ans = {"1120189568206855334755772969386322466504587771393281780479181280378649384474836640811321058",
					"901222374932223325127227268782264071473411707021904329768270353445551426496199895240029153",
					"743080893155670835190457624142660041242009519789634395609070717925831198977709780840111866",
					"869426224253371926613987858092124456757075432458316074243159343965137571525241299246709979",
					"1320887075413119861892973104106531418762115595594590334940245309481424478919307127876929347"};
			System.out.println("Ans: "+ Arrays.toString(h));
			System.out.println("Expected: "+Arrays.toString(ans));
			if (Arrays.equals(h, ans)) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);


		TestRunner.runTest(()->{
			HugeInteger a1 = new HugeInteger("0");
			HugeInteger a2 = new HugeInteger(0);
			HugeInteger a3 = new HugeInteger(0);
			a3.add(new HugeInteger("13424231412343124123431241234354568748576863243"));
			HugeInteger a4 = new HugeInteger("13424231412343124123431241234354568748576863243");
			a4.add(new HugeInteger(0));
			HugeInteger a5 = new HugeInteger(0);
			a5.add(new HugeInteger("0"));
			String[] h = new String[]{a1.toString(), a2.toString(), a3.toString(), a4.toString(), a5.toString()};
			String[] ans = {"0", "0", "13424231412343124123431241234354568748576863243",
					"13424231412343124123431241234354568748576863243", "0"};
			System.out.println("Ans: "+ Arrays.toString(h));
			System.out.println("Expected: "+Arrays.toString(ans));
			if (Arrays.equals(h, ans)) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			int[] h = {
					new HugeInteger(0).compareTo(0),
					new HugeInteger(10).compareTo(100),
					new HugeInteger(1324).compareTo(12),
					new HugeInteger(12343124).compareTo(23413412),
					new HugeInteger(321232).compareTo(321232),
			};
			int[] ans = {0,-1,1,-1,0};
			System.out.println("Ans: "+ Arrays.toString(h));
			System.out.println("Expected: "+Arrays.toString(ans));
			if (Arrays.equals(h, ans)) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			int[] h = {
					new HugeInteger("12343145326756245342").compareTo(new HugeInteger("12343145326756245342")),
					new HugeInteger("8653634").compareTo(new HugeInteger("895207654981329")),
					new HugeInteger("99719863246485372").compareTo(new HugeInteger("7896238475")),
					new HugeInteger("791823468712368493").compareTo(new HugeInteger("791827654312368493")),
					new HugeInteger("98321847").compareTo(new HugeInteger("0")),
			};
			int[] ans = {0,-1,1,-1,1};
			System.out.println("Ans: "+ Arrays.toString(h));
			System.out.println("Expected: "+Arrays.toString(ans));
			if (Arrays.equals(h, ans)) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			HugeInteger[] h = {new HugeInteger(9871234), new HugeInteger(7854678527134L), new HugeInteger(1234),
						new HugeInteger(0), new HugeInteger(9871234), new HugeInteger(8723),
						new HugeInteger(1123894761210L), new HugeInteger(7823168123494501395L),
						new HugeInteger(154154351), new HugeInteger(154154351)};
			Arrays.sort(h, HugeInteger::compareTo);
			long[] ans = {0, 1234, 8723, 9871234, 9871234, 154154351, 154154351,
					1123894761210L, 7854678527134L, 7823168123494501395L};
			System.out.println("Ans: "+ Arrays.toString(h));
			System.out.println("Expected: "+Arrays.toString(ans));
			if (Arrays.toString(h).equals(Arrays.toString(ans))) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);


		System.exit(0);

	}
}
