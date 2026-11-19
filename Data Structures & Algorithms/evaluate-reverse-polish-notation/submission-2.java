class Solution {
    public int evalRPN(String[] tokens) {
        int first = 0;
        int second = 0;
        int result = 0;

        Stack<Integer> stack = new Stack<>();

        for (String str : tokens) {

            if (!str.equals("+") && !str.equals("-")
                    && !str.equals("*") && !str.equals("/")) {
                stack.push(Integer.parseInt(str));
            }
            else {
                first = stack.pop();
                second = stack.pop();

                if (str.equals("+")) {
                    result = second + first;
                }
                else if (str.equals("-")) {
                    result = second - first;
                }
                else if (str.equals("*")) {
                    result = second * first;
                }
                else if (str.equals("/")) {
                    result = second / first;
                }

                stack.push(result);
            }
        }

        return stack.peek();
    }
}
