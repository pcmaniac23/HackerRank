// Problem: Lily's Homework

// Algorithm:
// (Ref: https://fizzbuzzer.com/lilys-homework-challenge/)
// 1. Only a sorted array (either ascending or descending) can be a candidate as a beautiful array,
//	  so we need to sort the input array first (remember we need to sort the array both ways)
// 2. Compare the input array against the sorted array and calculate the number of swaps needed
//		- Write a function like this: swap(orig, sorted)
//      - orig is the original array, sorted is the sorted array (either ascending or descending)
//      - Keep track of the locations of the elements in orig by using a map, m<position:value>
//      - iterate through orig, at each index 'i', compare the values orig[i] and sorted[i],
//		  if they equal, then no swap is needed, the value is at its expected location.
//		  Otherwise, find where the correct value is located in "orig", perform the swap, increment swap
//		  count, and update the new location of the value being swapped in the map
//		- Continue the above process until we've fully traversed the orig array, and we can get the swap
//		  count need to turn "orig" into "sorted"
// 3. Return the smaller of the number of swaps required between the ascend/descend sorted array

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

#include <algorithm>
#include <functional>

using namespace std;

int cnt_swap(vector<int> orig, vector<int> sorted) {
	unsigned int cnt = 0;
	
	// keep a record of the positions of values in the original array via a map
	// {value : position}
	unordered_map<int, int> m;
	for (int i = 0; i < orig.size(); i++) {
		m.insert(pair<int, int>(orig[i], i));
	}

	// iterate through orig and perform swap, count number of swaps along the way
	for (int i = 0; i < orig.size(); i++) {
		// value at index 'i' is wrong
		if (orig[i] != sorted[i]) {
			// find in orig where the correct value (sorted[i]) is
			int idx = m[sorted[i]];

			// swap the correct value to index 'i'
			int tmp = orig[i];
			orig[i] = orig[idx];
			orig[idx] = tmp;
			cnt++;	// increment swap count

			// update the new location of the value that we swapped away (the old value at index 'i')
			m[tmp] = idx;
		}
	}

	return cnt;
}

// Complete the lilysHomework function below.
int lilysHomework(vector<int> arr) {
	// ascending sort the input array
	vector<int> inc(arr);
	sort(begin(inc), end(inc));

	// descending sort the input array
	vector<int> dec(arr);
	sort(begin(dec), end(dec), greater<int>());

	// return the smaller of swap counts between ascending/descending sorted array
	return min(cnt_swap(arr, inc), cnt_swap(arr, dec));
}

int main(int argc, char* argv[]) {
	vector<int> input = { 656085744,592976686,3037922,82266352,17574000,344340000,8406892,591292449,569625472,899357375,251327440,301303036,281400020,77370228,15516426,82859300,88364436,39767760,148417500,306863056,10926174,118195200,310408774,309307894,200852782,82193280,424056750,249277128,180368880,477624006,86748948,7434336,48882310,112635040,6614541,503907132,598034610,160500171,70444416,72752680,271416096,30521205,529365648,399367584,129849984,263500556,76737948,464269640,613416088,162724716,163420800,720512988,1217212920,727647624,383190420,8350904,3456024,289141064,123384024,158867856,82005504,36225521,533012608,54370440,17671500,53627000,26597644,855638940,55343960,57828624,108025344,21431808,1182600,265643950,30054300,219553915,74203500,658061160,7502400,931691763,295769136,107345925,80109000,130922055,33544944,65280,452996453,301655430,7828912,425016000,297635898,26861016,739961600,928116,19645470,8691456,5123880,596100015,2735436,25596483,173620720,202797504,161748972,30122300,11082820,574006860,426732182,71136825,105659136,1808140278,450779280,286831620,104683008,938781480,175050736,255681692,67096152,119518575,15449840,25273458,165048960,5642130,85199958,354920488,446786340,131214816,41533296,25766518,90782304,59007600,700369740,122021794,56982366,238027920,434370816,223677580,72463156,355858300,144914616,145950,13822570,19914930,11072100,21450528,124958730,105156800,20843784,781192188,448358850,6139822,95694780,78713888,677177472,9963972,366432768,181113408,725292862,473528052,12864000,518355540,55832070,318508876,89963781,1796290329,844308846,428627693,276255100,123609720,440449488,27589680,426614166,110068200,408846096,620309228,186565236,49051552,561738897,650114105,32646556,7174400,275364045,945364797,3674160,66314292,11073770,14885370,245088324,669628848,33110250,971699976,324099072,259496060,492110802,52206516,508725376,1534995792,148078816,57993375,121071195,381960195,12496176,23728250,159836835,712982980,160098622,909675852,110400300,485423372,30637838,339925836,285371600,13618242,80809650,92375040,265612788,1151909241,234661320,16962144,213417000,269646860,1015650090,117439476,53164566,6946134,89506800,305469360,13406432,292353000,9969642,43982198,23887296,67730660,16384192,218824704,1082660306,1679473908,136336179,39265884,1077096020,464272368,87048192,56752487,156212388,360621525,8472816,17613600,62143172,82696127,79939536,155805468,159499963,262072360,39827904,179532360,2455040,327280740,148409340,73738980,3394872,3082560,225009981,188912256,179487784,340340,315171072,96680664,621206280,536379504,391714074,65055960,105570465,365721408,106712025,286764660 };
	
	int res = lilysHomework(input);
	cout << res << endl;
	
	return 0;
}