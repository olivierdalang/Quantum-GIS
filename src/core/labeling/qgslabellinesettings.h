/***************************************************************************
  qgslabellinesettings.h
  --------------------------
  Date                 : August 2020
  Copyright            : (C) 2020 by Nyall Dawson
  Email                : nyall dot dawson at gmail dot com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSLABELLINESETTINGS_H
#define QGSLABELLINESETTINGS_H

#include "qgis_core.h"
#include "qgis_sip.h"
#include "qgslabeling.h"
#include "qgsunittypes.h"
#include "qgsmapunitscale.h"
#include <QString>

class QgsPropertyCollection;
class QgsExpressionContext;

/**
 * \ingroup core
 * \class QgsLabelLineSettings
 *
 * Contains settings related to how the label engine places and formats
 * labels for line features (or polygon features which are labeled in
 * a "perimeter" style mode).
 *
 * \since QGIS 3.16
 */
class CORE_EXPORT QgsLabelLineSettings
{
  public:

    /**
     * Placement options for direction symbols.
     */
    enum class DirectionSymbolPlacement : int
    {
      SymbolLeftRight, //!< Place direction symbols on left/right of label
      SymbolAbove, //!< Place direction symbols on above label
      SymbolBelow //!< Place direction symbols on below label
    };

    /**
     * Returns the line placement flags, which dictate how line labels can be placed
     * above or below the lines.
     *
     * \see setPlacementFlags()
     */
    QgsLabeling::LinePlacementFlags placementFlags() const { return mPlacementFlags; }

    /**
     * Returns the line placement \a flags, which dictate how line labels can be placed
     * above or below the lines.
     *
     * \see placementFlags()
     */
    void setPlacementFlags( QgsLabeling::LinePlacementFlags flags ) { mPlacementFlags = flags; }

    /**
     * Returns TRUE if connected line features with identical label text should be merged
     * prior to generating label positions.
     *
     * \see setMergeLines()
     */
    bool mergeLines() const { return mMergeLines; }

    /**
     * Sets whether connected line features with identical label text should be merged
     * prior to generating label positions.
     *
     * \see mergeLines()
     */
    void setMergeLines( bool merge ) { mMergeLines = merge; }

    /**
     * Updates the thinning settings to respect any data defined properties
     * set within the specified \a properties collection.
     */
    void updateDataDefinedProperties( const QgsPropertyCollection &properties, QgsExpressionContext &context );

    /**
     * Returns TRUE if '<' or '>' (or custom strings set via leftDirectionSymbol and rightDirectionSymbol)
     * will be automatically added to the label text, pointing in the
     * direction of the line or polygon ring.
     *
     * \see setAddDirectionSymbol()
     * \see leftDirectionSymbol()
     * \see rightDirectionSymbol()
     * \see directionSymbolPlacement()
     * \see reverseDirectionSymbol()
     */
    bool addDirectionSymbol() const { return mAddDirectionSymbol; }

    /**
     * Sets whether '<' or '>' (or custom strings set via leftDirectionSymbol and rightDirectionSymbol)
     * will be automatically added to the label text, pointing in the
     * direction of the line or polygon ring.
     *
     * \see addDirectionSymbol()
     * \see setLeftDirectionSymbol()
     * \see setRightDirectionSymbol()
     * \see setDirectionSymbolPlacement()
     * \see setReverseDirectionSymbol()
     */
    void setAddDirectionSymbol( bool enabled ) { mAddDirectionSymbol = enabled; }

    /**
     * Returns the string to use for left direction arrows.
     *
     * \see setLeftDirectionSymbol()
     * \see addDirectionSymbol()
     * \see rightDirectionSymbol()
     */
    QString leftDirectionSymbol() const { return mLeftDirectionSymbol; }

    /**
     * Sets the string to use for left direction arrows.
     *
     * \see leftDirectionSymbol()
     * \see addDirectionSymbol()
     * \see rightDirectionSymbol()
     */
    void setLeftDirectionSymbol( const QString &symbol ) { mLeftDirectionSymbol = symbol; }

    /**
     * Returns the string to use for right direction arrows.
     *
     * \see setRightDirectionSymbol()
     * \see addDirectionSymbol()
     * \see leftDirectionSymbol()
     */
    QString rightDirectionSymbol() const { return mRightDirectionSymbol; }

    /**
     * Sets the string to use for right direction arrows.
     *
     * \see setLeftDirectionSymbol()
     * \see addDirectionSymbol()
     * \see rightDirectionSymbol()
     */
    void setRightDirectionSymbol( const QString &symbol ) { mRightDirectionSymbol = symbol; }

    /**
     * Returns TRUE if direction symbols should be reversed.
     *
     * \see setReverseDirectionSymbol()
     */
    bool reverseDirectionSymbol() const { return mReverseDirectionSymbol; }

    /**
     * Sets whether the direction symbols should be \a reversed.
     *
     * \see reverseDirectionSymbol()
     */
    void setReverseDirectionSymbol( bool reversed ) { mReverseDirectionSymbol = reversed; }

    /**
     * Returns the placement for direction symbols.
     *
     * This setting controls whether to place direction symbols to the left/right, above or below label.
     *
     * \see setDirectionSymbolPlacement()
     * \see addDirectionSymbol()
     */
    DirectionSymbolPlacement directionSymbolPlacement() const { return mPlaceDirectionSymbol; }

    /**
     * Sets the \a placement for direction symbols.
     *
     * This setting controls whether to place direction symbols to the left/right, above or below label.
     *
     * \see directionSymbolPlacement()
     * \see addDirectionSymbol()
     */
    void setDirectionSymbolPlacement( DirectionSymbolPlacement placement ) { mPlaceDirectionSymbol = placement; }

    /**
     * Returns the distance which labels are allowed to overrun past the start or end of line features.
     * \see setOverrunDistance()
     * \see overrunDistanceUnit()
     * \see overrunDistanceMapUnitScale()
     */
    double overrunDistance() const { return mOverrunDistance; }

    /**
     * Sets the \a distance which labels are allowed to overrun past the start or end of line features.
     * \see overrunDistance()
     * \see overrunDistanceUnit()
     * \see overrunDistanceMapUnitScale()
     */
    void setOverrunDistance( double distance ) {  mOverrunDistance = distance; }

    /**
     * Returns the units for label overrun distance.
     * \see setOverrunDistanceUnit()
     * \see overrunDistance()
     * \see overrunDistanceMapUnitScale()
     */
    QgsUnitTypes::RenderUnit overrunDistanceUnit() const {return mOverrunDistanceUnit; }

    /**
     * Sets the \a unit for label overrun distance.
     * \see overrunDistanceUnit()
     * \see overrunDistance()
     * \see overrunDistanceMapUnitScale()
     */
    void setOverrunDistanceUnit( const QgsUnitTypes::RenderUnit &unit ) { mOverrunDistanceUnit = unit;}

    /**
     * Returns the map unit scale for label overrun distance.
     * \see setOverrunDistanceMapUnitScale()
     * \see overrunDistance()
     * \see overrunDistanceUnit()
     */
    QgsMapUnitScale overrunDistanceMapUnitScale() const { return mOverrunDistanceMapUnitScale; }

    /**
     * Sets the map unit \a scale for label overrun distance.
     * \see overrunDistanceMapUnitScale()
     * \see overrunDistance()
     * \see overrunDistanceUnit()
     */
    void setOverrunDistanceMapUnitScale( const QgsMapUnitScale &scale ) { mOverrunDistanceMapUnitScale = scale; }

    /**
     * Returns the percent along the line at which labels should be placed.
     *
     * By default, this is 0.5 which indicates that labels should be placed as close to the
     * center of the line as possible. A value of 0.0 indicates that the labels should be placed
     * as close to the start of the line as possible, while a value of 1.0 pushes labels towards
     * the end of the line.
     *
     * \see setLineAnchorPercent()
     */
    double lineAnchorPercent() const { return mLineAnchorPercent; }

    /**
     * Sets the \a percent along the line at which labels should be placed.
     *
     * By default, this is 0.5 which indicates that labels should be placed as close to the
     * center of the line as possible. A value of 0.0 indicates that the labels should be placed
     * as close to the start of the line as possible, while a value of 1.0 pushes labels towards
     * the end of the line.
     *
     * \see lineAnchorPercent()
     */
    void setLineAnchorPercent( double percent ) { mLineAnchorPercent = percent; }

  private:
    QgsLabeling::LinePlacementFlags mPlacementFlags = QgsLabeling::LinePlacementFlag::AboveLine | QgsLabeling::LinePlacementFlag::MapOrientation;
    bool mMergeLines = false;
    bool mAddDirectionSymbol = false;
    QString mLeftDirectionSymbol = QString( '<' );
    QString mRightDirectionSymbol = QString( '>' );
    bool mReverseDirectionSymbol = false;
    DirectionSymbolPlacement mPlaceDirectionSymbol = DirectionSymbolPlacement::SymbolLeftRight;
    double mOverrunDistance = 0;
    QgsUnitTypes::RenderUnit mOverrunDistanceUnit = QgsUnitTypes::RenderMillimeters;
    QgsMapUnitScale mOverrunDistanceMapUnitScale;

    double mLineAnchorPercent = 0.5;
};

#endif // QGSLABELLINESETTINGS_H
