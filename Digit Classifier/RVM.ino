from sklearn.datasets import load_iris
from skbayes.rvm_ard_models import RVC
import warnings

# I get tons of boring warnings during training, so turn it off
warnings.filterwarnings("ignore")

iris = load_iris()
X = iris.data
y = iris.target
clf = RVC(kernel='rbf', gamma=0.001)
clf.fit(X, y)
y_predict = clf.predict(X)
