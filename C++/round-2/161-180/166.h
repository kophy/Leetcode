class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // use long type to avoid overflow
		long lnume = llabs(numerator);
		long ldeno = llabs(denominator);
		string integer = "";
		if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
			integer += "-";
		integer += to_string(lnume / ldeno);
		lnume = (lnume % ldeno) * 10;
		// end case 0: integer
		if (lnume == 0)
			return integer;

		unordered_map<int, int> index;
		
		string fraction = "";
		while (true) {
		    // end case 1: limited
			if (lnume == 0)
				break;
			// end case 2: loop
			if (index.find(lnume) != index.end()) {
			    fraction = fraction.substr(0, index[lnume]) + "(" + fraction.substr(index[lnume]) + ")";
				break;
			}
			index[lnume] = fraction.size();
			fraction.push_back(lnume / ldeno + '0');
			lnume = (lnume % ldeno) * 10;
		}
		
		return integer + "." + fraction;
    }
};