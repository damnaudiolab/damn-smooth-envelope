#include "PluginEditor.h"

PluginEditor::PluginEditor(PluginProcessor& p,
                           juce::AudioProcessorValueTreeState& vts)
  : AudioProcessorEditor(&p)
  , processorRef(p)
  , valueTreeState(vts)
{
  juce::ignoreUnused(processorRef);

  logo = juce::Drawable::createFromImageData(BinaryData::logo_svg,
                                             BinaryData::logo_svgSize);
  logo->setTransformToFit(headerArea.reduced(logoReduce).toFloat(),
                          juce::RectanglePlacement::centred);
  addAndMakeVisible(logo.get());

  setSize(bodyWidth, bodyHeight);

  addAndMakeVisible(amountSlider);
  amountSliderAttachment.reset(
    new SliderAttachment(valueTreeState, "amount", amountSlider));

  amountSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
  amountSlider.setTextBoxStyle(juce::Slider::TextBoxBelow,
                               false,
                               amountSliderTextBoxWidth,
                               amountSliderTextBoxHeight);
  amountSlider.setNumDecimalPlacesToDisplay(1);
  amountSlider.setColour(juce::Slider::ColourIds::textBoxOutlineColourId,
                         juce::Colours::transparentBlack);
  amountSlider.setBounds(amountSliderArea);
  // amountSlider.setLookAndFeel(&customLookAndFeel);
}

PluginEditor::~PluginEditor() {}

void
PluginEditor::paint(juce::Graphics& g)
{
  // (Our component is opaque, so we must completely fill the background with a
  // solid colour)
  g.fillAll(
    getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
  g.setColour(customLookAndFeel.colourPalette[CustomLookAndFeel::black]);
  g.fillRect(headerArea);
}

void
PluginEditor::resized()
{
  // layout the positions of your child components here
  auto area = getLocalBounds();
  area.removeFromBottom(50);
  // inspectButton.setBounds (getLocalBounds().withSizeKeepingCentre (100, 50));
}