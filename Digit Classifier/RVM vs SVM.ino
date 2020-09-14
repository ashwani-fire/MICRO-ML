uint8_t predict_rvm(double *x) {
    double decision[3] = { 0 };
    decision[0] = -0.6190847299428206;
    decision[1] = (compute_kernel(x,  6.3, 3.3, 6.0, 2.5) - 72.33233 ) * 0.228214 + -2.3609625;
    decision[2] = (compute_kernel(x,  7.7, 2.8, 6.7, 2.0) - 81.0089166 ) * -0.29006 + -3.360963;
    uint8_t idx = 0;
    double val = decision[0];
    for (uint8_t i = 1; i < 3; i++) {
        if (decision[i] > val) {
            idx = i;
            val = decision[i];
        }
    }
    return idx;
}

int predict_svm(double *x) {
    double kernels[10] = { 0 };
    double decisions[3] = { 0 };
    int votes[3] = { 0 };
        kernels[0] = compute_kernel(x,   6.7  , 3.0  , 5.0  , 1.7 );
        kernels[1] = compute_kernel(x,   6.0  , 2.7  , 5.1  , 1.6 );
        kernels[2] = compute_kernel(x,   5.1  , 2.5  , 3.0  , 1.1 );
        kernels[3] = compute_kernel(x,   6.0  , 3.0  , 4.8  , 1.8 );
        kernels[4] = compute_kernel(x,   7.2  , 3.0  , 5.8  , 1.6 );
        kernels[5] = compute_kernel(x,   4.9  , 2.5  , 4.5  , 1.7 );
        kernels[6] = compute_kernel(x,   6.2  , 2.8  , 4.8  , 1.8 );
        kernels[7] = compute_kernel(x,   6.0  , 2.2  , 5.0  , 1.5 );
        kernels[8] = compute_kernel(x,   4.8  , 3.4  , 1.9  , 0.2 );
        kernels[9] = compute_kernel(x,   5.1  , 3.3  , 1.7  , 0.5 );
        decisions[0] = 20.276395502
                    + kernels[0] * 100.0
                    + kernels[1] * 100.0
                    + kernels[3] * -79.351629954
                    + kernels[4] * -49.298850195
                    + kernels[6] * -40.585178082
                    + kernels[7] * -30.764341769
        ;
        decisions[1] = -0.903345464
                    + kernels[2] * 0.743494115
                    + kernels[9] * -0.743494115
        ;
        decisions[2] = -1.507856504
                    + kernels[5] * 0.203695177
                    + kernels[8] * -0.160020702
                    + kernels[9] * -0.043674475
        ;
        votes[decisions[0] > 0 ? 0 : 1] += 1;
        votes[decisions[1] > 0 ? 0 : 2] += 1;
        votes[decisions[2] > 0 ? 1 : 2] += 1;
                int classVal = -1;
        int classIdx = -1;
        for (int i = 0; i < 3; i++) {
            if (votes[i] > classVal) {
                classVal = votes[i];
                classIdx = i;
            }
        }
        return classIdx;
}
