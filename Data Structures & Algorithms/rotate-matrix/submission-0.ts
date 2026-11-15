class Solution {
    /**
     * @param {number[][]} matrix
     * @return {void}
     */
    rotate(matrix: number[][]): void {
        // traspose then vertically rotate
        let m: number = matrix.length
        let n: number = matrix[0].length
        for(let i = 0; i<m; i++){
            for(let j = 0; j<m; j++){
                if(i==j)break;
                let tmp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = tmp
            }
        }
        for(let i = 0; i<m; i++){
            for(let j = 0; j<m; j++){
                if(j>=n/2)break;
                let tmp = matrix[i][j]
                matrix[i][j] = matrix[i][n-j-1]
                matrix[i][n-j-1] = tmp
            }
        }
    }
}
