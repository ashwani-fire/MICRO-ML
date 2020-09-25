class perceptron
{

    float c = 0.00008;//constante de aprendizaje

  public:
    //arrays that hold inputs and weights
    float* inputs;
    float* weights;
    int n; //numero de entradas

    perceptron(int ninputs) {
      n = ninputs;
      inputs = new float[n];
      weights = new float[n];
      inputs[n - 1] = 1;//bias
      for (int i = 0; i < n; i++) {
        // The weights are picked randomly to start.
        //a trick to get values from -1 to 1
        weights[i] = (float)random(-1000, 1000) / 1000;
      }
    }

    //reset weights to random values
    void randomize() {
      for (int i = 0; i < n; i++) {
        // The weights are picked randomly to start.
        weights[i] = (float)random(-1000, 1000) / 1000;
      }
    }

    void setTraining(float t){
      c = t;

    }

    //training function
    void train(int desired, float guess) {
      float error = desired - guess;
      for (int i = 0; i < n; i++) {
        weights[i] += c * error * inputs[i];
      }
    }

    //forward function
    float feedForward() {
      float sum = 0;
      for (int i = 0; i < n; i++) {
        sum += inputs[i] * weights[i];
      }

      return activate(sum);
    }


   float weightedSum() {
      float sum = 0;
      for (int i = 0; i < n; i++) {
        sum += inputs[i] * weights[i];
      }

      return sum;
    }


  private:
    //activation function
    int activate(float sum) {
      //regresa 1 si es positivo, -1 si negativo.
      if (sum > 0) {
        return 1;
      }
      else {
        return -1;
      }
    }



};
