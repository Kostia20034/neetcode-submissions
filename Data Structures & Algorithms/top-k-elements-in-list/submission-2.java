
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        List<Integer>[] buckets = new ArrayList[nums.length + 1];
        Map<Integer, Integer> map = new HashMap<>();
        int highestFreq = 0;

        // Count frequencies
        for (int num : nums) {
            if (map.containsKey(num)) {
                map.put(num, map.get(num) + 1);
            } else {
                map.put(num, 1);
            }
        }

        // Populate buckets
        for (Integer key : map.keySet()) {
            int freq = map.get(key);

            if (buckets[freq] == null) {
                buckets[freq] = new ArrayList<>();
            }

            if (freq > highestFreq) {
                highestFreq = freq;
            }

            buckets[freq].add(key);
        }

        int[] result = new int[k];
        int index = 0;

        // Start from the highest frequency
        while (highestFreq > 0 && index < k) {
            if (buckets[highestFreq] != null) {
                for (int num : buckets[highestFreq]) {
                    result[index++] = num;

                    if (index == k) {
                        return result;
                    }
                }
            }

            highestFreq--;
        }

        return result;
    }
}

