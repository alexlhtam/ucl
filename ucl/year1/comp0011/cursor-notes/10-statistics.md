# Statistics

## I. Introduction

Statistics involves reasoning on datasets: measuring, representing, sampling, and testing hypotheses by confronting observed data with probability theory.

## II. Descriptive Statistics

### Population & Variables

- **Population**: the group being studied
- **Variable**: the measured quantity (qualitative or quantitative; if quantitative, discrete or continuous)

### Graphical Representations

- **Histogram**: bars where surface area above each value = frequency (proportion)
- **Density plot**: continuous version of a histogram; area under curve in a range = proportion of population in that range

### Measures of Central Tendency

**Mean** (average):

\[
\bar{x} = \frac{1}{n}\sum_{i=1}^n x_i
\]

- Sensitive to **extreme values** (outliers can skew the mean significantly)

**Median**: the value such that 50% of data points lie below and 50% above.

- If \(n\) is odd: the middle value (sorted data)
- If \(n\) is even: average of the two central values
- More robust to outliers than the mean

### Measures of Dispersion

**Standard deviation** (\(\sigma\) or SD):

\[
\sigma = \sqrt{\frac{1}{n}\sum_{i=1}^n (x_i - \bar{x})^2}
\]

Measures how spread out values are around the mean. The square of SD is the **variance**.

Datasets can have the same mean but very different standard deviations.

## III. Normal Distribution (in Statistics)

Many real-life datasets follow a **bell curve** (normal distribution).

If we know \(\mu\) (mean) and \(\sigma\) (standard deviation), we can approximate the distribution precisely. Useful property: approximately 68% of values within \(\pm 1\sigma\), 95% within \(\pm 2\sigma\), 99.7% within \(\pm 3\sigma\).

## IV. Sampling

When examining an entire population is infeasible, we study a **sample** and infer population properties.

**Key principles**:

- Larger samples are more trustworthy
- Samples should be taken as **randomly** as possible (avoid sampling bias)

### Confidence Intervals

A **confidence interval** quantifies the accuracy of an estimate from a sample.

At confidence level \(\alpha\) (e.g. 95%):

\[
\text{CI} = \left[\bar{x} - z_\alpha \frac{\sigma}{\sqrt{N}},\; \bar{x} + z_\alpha \frac{\sigma}{\sqrt{N}}\right]
\]

| Symbol | Meaning |
|---|---|
| \(\bar{x}\) | Sample mean |
| \(\sigma\) | Standard deviation in the sample |
| \(N\) | Sample size |
| \(z_\alpha\) | Confidence level constant (e.g. \(z_{95\%} \approx 1.96\)) |

**Properties**:

- The interval narrows as \(N\) grows (larger sample = more precision)
- The population mean \(\mu\) is likely inside the interval, but could still be outside
- "95% confidence" means: if we repeated the sampling many times, 95% of intervals would contain \(\mu\)

**Example**: For UCL student ages, sample mean \(\bar{x} \approx 22.4\), \(\sigma \approx 2.5\), \(N = 435\). The 95% CI is approximately \([22.16, 22.63]\).

## V. Hypothesis Testing

A structured method to determine whether observed data supports a claim.

### Procedure

**Step 1 -- State hypotheses**:

- \(H_0\) (Null Hypothesis): the "default" or no-effect scenario
- \(H_1\) (Alternative Hypothesis): the phenomenon we suspect

**Step 2 -- Choose a significance threshold** (typically 5% or 1%).

**Step 3 -- Gather data** and compute relevant statistics.

**Step 4 -- Compute the p-value**: the probability of obtaining results at least as extreme as observed, **assuming \(H_0\) is true**.

**Step 5 -- Compare**:

| Outcome | Decision |
|---|---|
| p-value \(< \alpha\) | Reject \(H_0\) (result is statistically significant) |
| p-value \(\geq \alpha\) | Cannot reject \(H_0\) (no conclusion) |

### Example: Testing a Coin for Bias

- \(H_0\): coin is fair (\(p = 0.5\))
- \(H_1\): coin is biased towards heads
- Toss 20 times, observe 15 heads
- p-value: \(\Pr(X \geq 15 \mid X \sim \text{Binomial}(20, 0.5)) \approx 0.02 = 2\%\)
- Since \(2\% < 5\%\), reject \(H_0\) -- evidence of bias

### Important Caveats

- The p-value is **not** the probability that \(H_0\) is true
- Different tests have different p-value formulas
- Beware of **p-value hacking** (running many tests until one is "significant")

## Exam Checklist

- [ ] Compute mean, median, and standard deviation
- [ ] Interpret histograms and density plots
- [ ] Understand when mean is misleading vs median
- [ ] Construct confidence intervals using the formula
- [ ] Set up a hypothesis test: define \(H_0\), \(H_1\), significance level
- [ ] Compute and interpret p-values
- [ ] Identify sampling bias
