class Solution {
    double radius, xc, yc;

    public Solution(double radius, double x_center, double y_center) {
        this.radius = radius;
        this.xc = x_center;
        this.yc = y_center;
    }

    public double[] randPoint() {
        while (true) {
            double  x = Math.random() * 2 * this.radius - this.radius;
            double y = Math.random() * 2 * this.radius - this.radius;
            if (x * x + y * y <= this.radius * this.radius) {
                return new double[] {xc + x, yc + y};
            }
        }
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.randPoint();
 */