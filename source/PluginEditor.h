#pragma once

#include "PluginProcessor.h"
// #include "melatonin_inspector/melatonin_inspector.h"

//==============================================================================
class PluginEditor : public juce::AudioProcessorEditor
{
public:
  explicit PluginEditor(PluginProcessor&, juce::AudioProcessorValueTreeState&);
  ~PluginEditor() override;

  //==============================================================================
  void paint(juce::Graphics&) override;
  void resized() override;

private:
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
  CustomLookAndFeel customLookAndFeel;

  int bodyWidth = 250;
  int bodyHeight = 350;

#define wCent bodyWidth / 100;
#define hCent bodyHeight / 100;

  int headerHeight = 20 * hCent;

  int amountSliderPosX = 10 * wCent;
  int amountSliderPosY = 30 * hCent;
  int amountSliderWidth = 80 * wCent;
  int amountSliderHeight = 65 * hCent;

  int amountSliderTextBoxWidth = 20 * wCent;
  int amountSliderTextBoxHeight = 10 * hCent;

  int logoReduce = 4 * hCent;

  std::unique_ptr<juce::Drawable> logo;

  juce::Rectangle<int> bodyArea{ 0, 0, bodyWidth, bodyHeight };

  juce::Rectangle<int> headerArea{ 0, 0, bodyWidth, headerHeight };

  juce::Rectangle<int> amountSliderArea{ amountSliderPosX,
                                         amountSliderPosY,
                                         amountSliderWidth,
                                         amountSliderHeight };

  juce::Slider amountSlider;
  std::unique_ptr<SliderAttachment> amountSliderAttachment;

  PluginProcessor& processorRef;

  juce::AudioProcessorValueTreeState& valueTreeState;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};